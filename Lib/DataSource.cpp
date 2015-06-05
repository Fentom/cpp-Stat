#include "DataSource.h"


DataSource::DataSource(Fichier & file, const string Nom, const string Sujet, int type, int col)
{
	setNom(Nom);
	setSujet(Sujet);
	setType(type);
	setEffTotal(0);
}
DataSource::DataSource(const DataSource & d)
{
	setNom(d.getNom());
	setSujet(d.getSujet());
	setType(d.getType());
	setEffTotal(d.getEffTotal());
}
DataSource::~DataSource()
{

}
