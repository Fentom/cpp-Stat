#include "SerieStatistique2D.h"

SerieStatistique2D::SerieStatistique2D(Echantillon * sample)
{
	DataSource2D * datasource = dynamic_cast<DataSource2D*>(sample->getDataSource());
	if(datasource) 
	{
		data = datasource;
		// cout << "This is your data : " << endl << data->toString();

		// cout << "it's done subject 2 is " << data->getSujet2() << endl;
	}
	else
		cout << "Erreur : recuperation de la datasource2D. " << endl;
}

SerieStatistique2D::SerieStatistique2D(const SerieStatistique2D & old)
{
	
}

SerieStatistique2D::~SerieStatistique2D()
{
}

float SerieStatistique2D::getMoyVal1() const
{
	float somme = 0;

	for (int i = 0; i < data->getValueCount(); ++i)
	{
		somme = somme + data->getXi(i);
	}

	return somme/data->getEffTotal();
}

float SerieStatistique2D::getMoyVal2() const
{
	float somme = 0;

	for (int i = 0; i < data->getValueCount(); ++i)
	{
		somme = somme + data->getYi(i);
	}

	return somme/data->getEffTotal();
}

float SerieStatistique2D::getCorrelation() const
{
	float sommeXi = 0, sommeYi = 0, sommeXiYi = 0, numerateur = 0, sommeXiCarre = 0, sommeYiCarre = 0, denominateur = 0;

	for (int i = 0; i < data->getValueCount(); ++i)
	{
		sommeXi = sommeXi + data->getXi(i);
		sommeYi = sommeYi + data->getYi(i);
		sommeXiYi = sommeXiYi + (data->getXi(i) * data->getYi(i));
		sommeXiCarre = sommeXiCarre + (pow(data->getXi(i), 2));
		sommeYiCarre = sommeYiCarre + (pow(data->getYi(i), 2));
	}

	numerateur = sommeXiYi - ((sommeXi) * (sommeYi)) / data->getEffTotal();
	denominateur = sqrt((sommeXiCarre - pow(sommeXi, 2)/data->getEffTotal())*(sommeYiCarre - pow(sommeYi, 2)/data->getEffTotal()));

	return numerateur/denominateur;
}

float SerieStatistique2D::getA() const
{
	float sommeXi = 0, sommeYi = 0, sommeXiYi = 0, sommeXiCarre = 0, numerateur = 0, denominateur = 0;

	for (int i = 0; i < data->getValueCount(); ++i)
	{
		sommeXi = sommeXi + data->getXi(i);
		sommeYi = sommeYi + data->getYi(i);
		sommeXiYi = sommeXiYi + (data->getXi(i) * data->getYi(i));
		sommeXiCarre = sommeXiCarre + (pow(data->getXi(i), 2));
	}

	numerateur = sommeXiYi - (sommeXi*sommeYi)/ data->getEffTotal();
	denominateur = sommeXiCarre - (pow(sommeXi, 2)/ data->getEffTotal());

	return numerateur/denominateur;

}
float SerieStatistique2D::getB() const
{
	return getMoyVal2() - getA() * getMoyVal1();
}


void SerieStatistique2D::AfficheRapport() const
{
	cout << "Rapport:" << endl;
	cout << "Nom: " << data->getNom() << endl;
	cout << "Sujet 1 de l'etude: " << data->getSujet() << endl;
	cout << "Sujet 2 de l'etude: " << data->getSujet2() << endl;

	cout << data->toString() << endl;

	cout << "Effectif total: " << data->getEffTotal() << endl;
	cout << "Moyenne val1: " << getMoyVal1() << endl;
	cout << "Moyenne val2: " << getMoyVal2() << endl << endl;

	cout << "Coefficient de correlation: " << getCorrelation() << "%" << endl;
	cout << "Valeur de A: " << getA() << endl;
	cout << "Valeur de B: " << getB() << endl;

	Previsions();
}

void SerieStatistique2D::Previsions() const
{
	int choix;
	string saisie;
	float val = 0, result = 0;

	do
	{
		choix = this->Menu();	

		switch(choix)
		{
			// sur base de la formule : y = ax + b
			case 1:
				// on nous donne un X, on calcule le Y
				cout << "Entrez la valeur pour " << data->getSujet() << " : " << endl;
				cin >> saisie;

				val = (float)atof(saisie.c_str());
				result = getA()*val + getB();

				cout << "La valeur prevue : " << result << endl;
			break;
			case 2:
				// on nous donne le Y, on calcule le X
				cout << "Entrez la valeur pour " << data->getSujet2() << " : " << endl;
				cin >> saisie;

				val = (float)atof(saisie.c_str());
				result = (val/getA()) - getB();

				cout << "La valeur prevue : " << result << endl;
			break;
		}
	} while (choix != 3);
}


int SerieStatistique2D::Menu() const
{
	string choice;

	cout << endl << "1. Previsions pour : " << data->getSujet() << endl;
	cout << "2. Previsions pour : " << data->getSujet2() << endl;
	cout << "3. Sortie." << endl;

	cout << endl << "Votre choix : ";
	cin >> choice;

	return (int)atoi(choice.c_str());
}
