#ifndef DATA_SOURCE2D_H
#define DATA_SOURCE2D_H

#include "DataSource.h"
#include "Data2D.h"
#include "ListeS.h"
#include <string>

using namespace std;

class DataSource2D : public DataSource
{
	private:
		ListeS<Data2D> * list;
		string _Sujet2;
		char _Type2;
	public:
		DataSource2D(Fichier & file, const string Nom, const string Sujet, const string Sujet2, int type, int type2, int col, int col2);
		~DataSource2D();

		void loadFile(Fichier & f, int col1, int col2);
		float getXi(int index) const;
		float getYi(int index) const;
		string getSujet2() const {return _Sujet2;}
		char getType2() const { return _Type2; }
		ListeS<Data2D> * getL();


		inline int getValueCount() const { return list->getNombreElements(); }
		inline bool isEmpty() const { return getValueCount() == 0; }
		string toString() const;
};

#endif // DATA_SOURCE2D_H
