#include "Echantillon.h"
#include "SerieStatistique1D.h"
#include "SerieStatistique2D.h"
#include "ListeS.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Lancement du programme" << endl;

    if (argc == 2)
    { cout << "Etude 1D" << endl;
        Echantillon * E1 = new Echantillon(argv[1], 1, 0);
        // E1->Affiche();
        SerieStatistique1D C1D(E1);
        C1D.AfficheRapport();
        exit(0);
    }
    if (argc == 3)
    { cout << "Etude 1D" << endl;
        Echantillon * E1 = new Echantillon(argv[1],atoi(argv[2]), 0);
        // E1->Affiche();
        SerieStatistique1D C1D(E1);
        C1D.AfficheRapport();
        exit(0);
    }
    if (argc == 4)
    { cout << "Etude 2D" << endl;
        Echantillon * E1 = new Echantillon(argv[1],atoi(argv[2]),atoi(argv[3]));
        SerieStatistique2D C2D(E1);
        C2D.AfficheRapport();
        exit(0);
    }

    return 0;
}
