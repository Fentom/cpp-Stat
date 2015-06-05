// Denys Mercenier

#include "DataSource.h"
#include "ExceptionBase.h"
#include "Echantillon.h"
#include "SerieStatistique1D.h"
#include "SerieStatistique2D.h"
#include <qapplication.h>

#include "faffichage.h"

FAffichage* F1; 
void *Graph2D(void* D);
int	Continue = 1;

#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <iostream.h>
int	Argc;
char**	Argv;
CEchantillon*	E1;

pthread_t	Hand;
pthread_cond_t Cond;
pthread_mutex_t Mutex;

float    a , b,aMoyenne,
         aMediane,
         aEcartType;
int main(int argc, char* argv[])
{

Argc = argc;
Argv = argv;
cout << "on commence" << argc <<  endl;
if (argc == 2)
   { E1 = new CEchantillon(argv[1],1);
     E1->Affiche();
     CSerieStatistique1D	C1D(E1);
     C1D.AfficheRapport();
     exit(0);
   }
if (argc == 3)
   { E1 = new CEchantillon(argv[1],atoi(argv[2]));
     E1->Affiche();
     CSerieStatistique1D	C1D(E1);
     C1D.AfficheRapport();
     exit(0);
   }
if (argc == 4)
   { cout << "Etude 2D" << endl;
     E1 = new CEchantillon(argv[1],atoi(argv[2]),atoi(argv[3]));
     if ((errno = pthread_mutex_init(&Mutex,NULL)) != 0)
     { perror("Err. de pthread_mutex_init() : ");
     exit(1);
     }
     if ((errno = pthread_cond_init(&Cond,NULL)) != 0)
     { perror("Err. de pthread_cond_init() :");
     exit(1);
     }
     pthread_create(&Hand,NULL,Graph2D,(void*)E1->getSource());
     CSerieStatistique2D	C2D(E1);
     if ((errno = pthread_mutex_lock(&Mutex)) != 0)
     { perror("Err. de pthread_mutex_lock() :");
     exit(1);
     }
     while(Continue)
     { if ((errno = pthread_cond_wait(&Cond,&Mutex)) != 0)
     { perror("Err. de pthread_cond_signal() :");
     exit(1);
     }
     C2D.setMoyenne();
     C2D.setA();
     C2D.setB();
     C2D.setCorr();
     }
     if ((errno = pthread_mutex_unlock(&Mutex)) != 0)
     { perror("Err. de pthread_mutex_lock() ");
     exit(1);
     }
     C2D.Affiche();
     C2D.Prevision();
   }
cout << "fin" << endl;
}

void *Graph2D(void* D)
{
CDataSource2D* DD = (CDataSource2D*)D;
QApplication a( Argc, Argv );
    F1 = new FAffichage(DD);
    F1->show();
    a.exec();
return NULL;
}
