#include "DataSourceSerieDiscrete.h"
#include <iostream>

using namespace std;

DataSourceSerieDiscrete::DataSourceSerieDiscrete(
	Fichier & file, const string Nom, const string Sujet, int type, int col)
	: DataSource(file, Nom, Sujet, type, col)
{
	list = new ListeTriee<Data1D>();
	loadFile(file, col);
}

DataSourceSerieDiscrete::DataSourceSerieDiscrete(const DataSourceSerieDiscrete & d)
: DataSource(d)
{
	cout << "in copy constructor" << endl;
	if (d.getL() != NULL)
		list = new ListeTriee<Data1D>(*(d.getL()));

	cout << "done" << endl;
}

DataSourceSerieDiscrete::~DataSourceSerieDiscrete()
{
	if (list != NULL)
		delete list;
}

void DataSourceSerieDiscrete::loadFile(Fichier & f, int col)
{
	ListeS<string> splittedline;
	Data1D data;
	ListeTriee<float> listeT;
	float nbr;

	while (!f.end())
	{
		splittedline = f.readLine(':');
		listeT.insere((float)atof(splittedline.get(col).c_str()));
	}

	int c = 1;
	float valueold = listeT.get(0);
	float valuenew;

	for (int i = 1; i < listeT.getNombreElements() ; ++i)
	{
		valuenew = listeT.get(i);

		if(valueold == valuenew)
			c++;
		else
		{
			data.setValue(valueold);
			data.setEffective(c);
			list->insere(data);
			setEffTotal(getEffTotal() + c);
			c = 1;
			valueold = valuenew;
		}
	}

	data.setValue(valueold);
	data.setEffective(c);
	list->insere(data);
	setEffTotal(getEffTotal() + c);

	// list->affiche();
}

float DataSourceSerieDiscrete::getXi(int index) const
{
	return list->get(index).getValue();
}
float DataSourceSerieDiscrete::getYi(int index) const
{
	return list->get(index).getEffective();
}
ListeTriee<Data1D> * DataSourceSerieDiscrete::getL() const
{
	return list;
}

string DataSourceSerieDiscrete::toString() const
{
	if (!list || list->getNombreElements() == 0)
		return "Source de donnee vide";

	string st;

	st += "Etude d'une variable discrete\n";
	st += "    Val  : Effectif\n";
	st += "_______________________\n";
	for (int i = 0; i < list->getNombreElements(); ++i) {
		st += Utils::float2string(list->get(i).getValue()) + " : " + Utils::float2string(list->get(i).getEffective()) + "\n";
	}

	return st;
}


