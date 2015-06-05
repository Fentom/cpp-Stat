#include "DataSource2D.h"

DataSource2D::DataSource2D(Fichier & file, const string Nom, const string Sujet, 
	const string Sujet2, int type, int type2, int col, int col2) : 
	DataSource(file, Nom, Sujet, type, col)
{
	_Type2 = type2;
	_Sujet2 = Sujet2;
	list = new ListeS<Data2D>();
	loadFile(file, col, col2);
}
DataSource2D::~DataSource2D()
{
	if (list != NULL)
		delete list;
}

void DataSource2D::loadFile(Fichier & f, int col1, int col2)
{
	Fichier f2(f);
	ListeS<string> splittedline;
	ListeS<float> listeTmp1;
	ListeS<float> listeTmp2;
	Data2D data;

	data.setValue2(1);

	while (!f.end())
	{
		splittedline = f.readLine(':');
		listeTmp1.insere((float)atof(splittedline.get(col1).c_str()));
	}

	// listeTmp1.affiche();

	while (!f2.end())
	{
		splittedline = f2.readLine(':');
		listeTmp2.insere((float)atof(splittedline.get(col2).c_str()));
	}

	// listeTmp2.affiche();

	for (int i = 0; i < listeTmp1.getNombreElements(); ++i)
	{
		data.setValue1(listeTmp1.get(i));
		data.setValue2(listeTmp2.get(i));
		list->insere(data);
	}

	setEffTotal(list->getNombreElements());
	// list->affiche();
}

float DataSource2D::getXi(int index) const
{
	return list->get(index).getValue1();
}
float DataSource2D::getYi(int index) const
{
	return list->get(index).getValue2();
}
ListeS<Data2D> * DataSource2D::getL()
{
	return list;
}

string DataSource2D::toString() const
{
	if (!list)
		return "Vide";
	string st;
	st += "Etude a 2 dimensions\n";
	st += "     X    :     Y\n";
	st += "_______________________\n";
	for (int i = 0; i < list->getNombreElements(); ++i) {
		st += Utils::float2string(list->get(i).getValue1()) + " : " + Utils::float2string(list->get(i).getValue2()) + "\n";
	}

	return st;
}
