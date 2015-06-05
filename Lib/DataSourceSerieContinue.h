#ifndef DATA_SOURCE_SERIE_CONTINUE_H
#define DATA_SOURCE_SERIE_CONTINUE_H

#include "DataSource.h"
#include "Data1D.h"
#include "ListeS.h"
#include "ListeTriee.h"
#include <string>

using namespace std;

class DataSourceSerieContinue : public DataSource
{
	private:
		ListeTriee<Data1D> * list;
		float debut;
		float interval;
	public:
		DataSourceSerieContinue(Fichier & file, const string Nom, const string Sujet, int type, int col);
		DataSourceSerieContinue(const DataSourceSerieContinue & data);
		~DataSourceSerieContinue();

		void loadFile(Fichier & f, int c);
		float getXi(int index) const;
		float getYi(int index) const;
 		float getInterval() const;
		ListeTriee<Data1D> * getL() const;

		inline int getValueCount() const { return list->getNombreElements(); }
		inline bool isEmpty() const { return getValueCount() == 0; }
		string toString() const;
};

#endif // DATA_SOURCE_SERIE_CONTINUE_H
