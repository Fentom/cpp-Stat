#include "SerieStatistique1D.h"

SerieStatistique1D::SerieStatistique1D(Echantillon * sample)
{
	DataSource * datasource = sample->getDataSource();
	data = datasource;
	
	if(datasource->getType() == 'C')
		type = CONTINUE;
	else
		type = DISCRETE;

	// cout << "This is your data : " << endl << data->toString();

	// cout << "it's done" << endl;
}

SerieStatistique1D::SerieStatistique1D(const SerieStatistique1D & old)
{
	
}

SerieStatistique1D::~SerieStatistique1D()
{
}

float SerieStatistique1D::getMediane() const
{
	int cible;

	cible = (data->getEffTotal()-1) / 2; // pour effectif=2n+1 -> ceci est n+1

	if (data->getEffTotal()%2 != 0)
	{ 	// Effectif total impaire
		return getXiFromEffectiveNum(cible);
	}

	// Effectif total paire
	return (getXiFromEffectiveNum(cible) + getXiFromEffectiveNum(cible-1)) / 2;
}

float SerieStatistique1D::getXiFromEffectiveNum(int effectiveInd) const
{
	float mediane;
	float effCumul = 0, eff = 0;
	int i, x = 0;
	while (effCumul < effectiveInd)
	{
		eff = data->getYi(x);
		i = 0;
		while(i < eff && effCumul < effectiveInd)
		{
			++effCumul;
			++i; // En sortant, i contient la position de la mediane dans l'intervalle
		}
		++x; // On incrémente une fois de trop en sortant -> x-1
	}
	mediane = data->getXi(x - 1);
	// On met a niveau la valeur selon la position au sein de la classe pour les séries continues
	if (type == CONTINUE)
	{
		float debutClasse = mediane - ((DataSourceSerieContinue*)data)->getInterval()/2;
		
		mediane = (float)debutClasse +\
				(((DataSourceSerieContinue*)data)->getInterval() / eff)\
				* i;
	}
	return mediane;
}

ListeTriee<float> SerieStatistique1D::getModes() const
{
	ListeTriee<float> list;
	float biggest;
	int biggestIndex;

	// Recherche du mode
	biggest = data->getYi(0);
	biggestIndex = 0;

	for (int i = 1; i < data->getValueCount(); ++i)
	{
		if (data->getYi(i) > biggest)
		{
			biggest = data->getYi(i);
			biggestIndex = i;
		}
	}

	// Ajout dans la liste de tout les modes
	for (int i = 0; i < data->getValueCount(); ++i)
	{
		if (data->getYi(i) == biggest)
			list.insere(data->getXi(i));
	}

	return list;
}

float SerieStatistique1D::getMoyenne() const
{
	float somme = 0;

	for (int i = 0; i < data->getValueCount(); ++i)
	{
		somme = somme + data->getXi(i) * data->getYi(i);
	}

	return somme/data->getEffTotal();
}

float SerieStatistique1D::getVariance() const
{
	double somme;
	float ecart_moyenne;

	for (int i = 0; i < data->getValueCount(); ++i)
	{
		ecart_moyenne = data->getXi(i) - getMoyenne();
		somme = somme + data->getYi(i) * pow(ecart_moyenne, 2);
	}

	return (float)(somme / data->getEffTotal());
}

/*
 * @return: 0 si sous controle
 * 			1 si on suspecte un probleme
 * 			2 si le processus est hors controle
 */
int SerieStatistique1D::getControlState() const
{
	int ret = 0;
	float min = getMoyenne() - 2 * getEcartType();
	float max = getMoyenne() + 2* getEcartType();
	float mincontrol = min - getEcartType();
	float maxcontrol = max + getEcartType();

	float val;

	for (int i = 0; i < data->getEffTotal() ; ++i)
	{
		val = getXiFromEffectiveNum(i);
		if (val < min || val > max)
		{
			if (val < mincontrol || val > maxcontrol)
				return 2;
			else
				ret = 1;
		}
	}
	return ret;
}

void SerieStatistique1D::AfficheRapport() const
{
	cout << "Rapport:" << endl;
	cout << "Nom: " << data->getNom() << endl;
	cout << "Sujet de l'etude: " << data->getSujet() << endl;
	cout << data->toString() << endl;

	cout << "Effectif total: " << data->getEffTotal() << endl;
	cout << "Moyenne: " << getMoyenne() << endl;
	cout << "Mediane: " << getMediane() << endl;

	if (getModes().getNombreElements() > 1)
	{
		cout << "Modes: " << endl;
		getModes().affiche();
	}
	else
		cout << "Mode: " << getMode() << endl;

	cout << "Etendue: " << getEtendue() << endl;
	cout << "Ecart type: " << getEcartType() << endl;
	cout << "Variance: " << getVariance() << endl;
	cout << "Coefficient de variation: " << getCoefVariation() << "%" << endl;

	cout << endl << "Controle de qualite: " << endl;
	cout << "Valeur min: " << getMinVal() << endl;;
	cout << "Valeur max: " << getMaxVal() << endl;
	cout << endl;

	switch (getControlState())
	{
		case 0:
			cout << "Valeurs de la statistique sous controle." << endl;
			break;
		case 1:
			cout << "On suspecte un probleme" << endl;
			break;
		case 2:
			cout << "Le processus est hors controle" << endl;
			break;
	}
}
