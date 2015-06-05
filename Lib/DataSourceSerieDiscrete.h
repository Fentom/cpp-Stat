#ifndef DATA_SOURCE_SERIE_DISCRETE_H
#define DATA_SOURCE_SERIE_DISCRETE_H

#include "DataSource.h"
#include "Data1D.h"
#include "ListeS.h"
#include "ListeTriee.h"
#include <string>

using namespace std;

class DataSourceSerieDiscrete : public DataSource
{
	private:
		ListeTriee<Data1D> * list;
	public:
		DataSourceSerieDiscrete(Fichier & file, const string Nom, const string Sujet, int type, int col);
		DataSourceSerieDiscrete(const DataSourceSerieDiscrete & data);
		~DataSourceSerieDiscrete();

		void loadFile(Fichier & f, int c);
		float getXi(int index) const;
		float getYi(int index) const;
		ListeTriee<Data1D> * getL() const;

		inline int getValueCount() const { return list->getNombreElements(); }
		inline bool isEmpty() const { return getValueCount() == 0; }
		string toString() const;
};

#endif // DATA_SOURCE_SERIE_DISCRETE_H
