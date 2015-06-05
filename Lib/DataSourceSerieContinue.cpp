#include "DataSourceSerieContinue.h"
#include <iostream>
#include <sstream>

using namespace std;

DataSourceSerieContinue::DataSourceSerieContinue(
	Fichier & file, const string Nom, const string Sujet, int type, int col)
	: DataSource(file, Nom, Sujet, type, col)
{
	list = new ListeTriee<Data1D>();
	loadFile(file, col);
}

DataSourceSerieContinue::DataSourceSerieContinue(const DataSourceSerieContinue & d)
: DataSource(d)
{
	debut = d.debut;
	interval = d.interval;
	
	if (d.getL())
		list = new ListeTriee<Data1D>(*d.getL());
}

DataSourceSerieContinue::~DataSourceSerieContinue()
{
	if (list != NULL)
		delete list;
}

void DataSourceSerieContinue::loadFile(Fichier & f, int col)
{
	ListeS<string> splittedline;
	Data1D data;
	ListeTriee<Data1D> listeTmp;
	float nbr;

	data.setEffective(1);
	stringstream ss;

	// on insére toutes les valeurs dans une liste temporaire
	while (!f.end())
	{
		splittedline = f.readLine(':');
		ss << splittedline.get(col);
		ss >> nbr;
		data.setValue(nbr);
		listeTmp.insere(data);

		ss.clear();//clear any bits set
		ss.str(std::string());
	}

    cout << "Valeurs:" << endl;
    listeTmp.affiche();

    cout << "Veuillez preciser la valeur de depart de la premiere classe: ";
    cin >> this->debut;
    cout << "Veuillez preciser la taille de l'intervalle: ";
    cin >> this->interval;

    // On remplit la liste avec les moyennes des classes et 0 effectifs
    float x = debut + interval/2;

    while(x < listeTmp.get(listeTmp.getNombreElements() - 1).getValue())
    {
		list->insere(Data1D(x, 0));
		x += interval;
	}

    // On rajoute les valeurs de ListeTmp dans la vraie liste mais en les placant dans une classe
    float classMin = debut;
    x = debut + interval/2;
    float classMax = classMin + interval;

    for (int i = 0; i < listeTmp.getNombreElements(); ++i)
    {
    	// Trouver la moyenne de classe correspondant à cette valeur
    	// Etant donne que la liste est ordonnee, inutile de remettre x au debut a chaque fois
    	while(listeTmp.get(i).getValue() >= classMax)
    	{
    		x += interval;
    		classMax += interval;
    	}

    	for (int j = 0; j < list->getNombreElements(); ++j)
    	{
    		if ((list->get(j)).getValue() == x)
    		{
    			(list->get(j))++;
    		}
    	}

		setEffTotal(getEffTotal() + 1);
    }

    // cout << "this is the source of data " << endl;
	// list->affiche();

	// cout << "effectif total : " << getEffTotal() << endl;
}

float DataSourceSerieContinue::getInterval() const
{
	return interval;
}

float DataSourceSerieContinue::getXi(int index) const
{
	return list->get(index).getValue();
}

float DataSourceSerieContinue::getYi(int index) const
{
	return list->get(index).getEffective();
}

ListeTriee<Data1D> * DataSourceSerieContinue::getL() const
{
	return list;
}

string DataSourceSerieContinue::toString() const
{
	if (!list)
		return "Vide";
	string st;
	st += "Etude d'une variable continue\n";
	st += "    Val  : Effectif\n";
	st += "_______________________\n";
	for (int i = 0; i < list->getNombreElements(); ++i) {
		st += Utils::float2string(list->get(i).getValue()) + " : " + Utils::float2string(list->get(i).getEffective()) + "\n";
	}

	return st;
}
