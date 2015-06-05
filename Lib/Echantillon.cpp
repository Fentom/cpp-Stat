#include "Echantillon.h"
#include <iostream>


using namespace std;

Echantillon::Echantillon(string file_name, int col1, int col2)
{
	Fichier f(file_name);

	// On transforme les colonnes en indices.
	--col1;
	--col2;

	string nom = f.readLine();
	ListeS<string> lsujet = f.readLine(':');
	ListeS<string> ltype = f.readLine(':');

	// lsujet.affiche();
	// ltype.affiche();

	// cout << "Voici les resultats :" << endl;
	// cout << "nom : " << nom << endl;
	// cout << "sujet : " << lsujet.get(col1) << endl;
	// cout << "type : " << ltype.get(col1).at(0) << endl;

	if (col2 < 0)
	{
		switch(ltype.get(col1).at(0))
		{
			case 'C':
				source = new DataSourceSerieContinue(f, nom, lsujet.get(col1), ltype.get(col1).at(0), col1);
				break;
			case 'D':
				source = new DataSourceSerieDiscrete(f, nom, lsujet.get(col1), ltype.get(col1).at(0), col1);
				break;
		}
	}
	else
	{
		// cout << "2D" << endl;
		// cout << "sujet2 : " << lsujet.get(col2) << endl;
		// cout << "type2 : " << ltype.get(col2).at(0) << endl;
		source = new DataSource2D(f, nom, lsujet.get(col1), lsujet.get(col2), ltype.get(col1).at(0), ltype.get(col2).at(0), col1, col2);
	}
}
Echantillon::~Echantillon()
{
	if (source != NULL)
		delete source;
}

string Echantillon::toString() const
{
	if (!this->source)
		return "Cet echantillon ne contient pas de source de donnee.";

	string st;

	st += source->toString();

	return st;
}
