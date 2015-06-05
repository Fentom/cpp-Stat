#include <iostream>
using namespace std;

#include "Echantillon.h"
#include "Data1D.h"
#include "DataSourceSerieDiscrete.h"
#include "SerieStatistique1D.h"
#include "SerieStatistique2D.h"

int main()
{
  Echantillon * sample = new Echantillon("Donnee1DDiscrete.txt", 1, 2);


  cout << "Creation de l'objet stat" << endl;
  SerieStatistique2D stat(sample);
  cout << "Obj created" << endl;

  stat.AfficheRapport();

  exit(0);
}

