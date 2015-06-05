#ifndef ECHANTILLON_H
#define ECHANTILLON_H

#include "DataSourceSerieContinue.h"
#include "DataSourceSerieDiscrete.h"
#include "DataSource2D.h"
#include "Fichier.h"
#include "ListeS.h"
#include "ListeTriee.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Echantillon
{
	private:
		DataSource * source;
	public:
		Echantillon(string file_name, int = 1, int = 0);
		~Echantillon();

		inline DataSource * getDataSource() {return source;}
		string toString() const;
};


#endif // ECHANTILLON_H
