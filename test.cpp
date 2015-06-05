#include <iostream>
using namespace std;

#include "ListeS.h"
#include "Data1D.h"
#include <string>

int  Menu();
void Essai1();
void Essai2();

int main()
{
  int choix;
  bool fini = false;
  srand((unsigned)time(NULL));

  while(!fini)
  {
    choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      default : fini = true ; break;
    }
  }

  exit(0);
}

int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 (classe ListeS) ------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template ListeS avec des entiers" << endl;
  cout << " 2. Test du template ListeS avec des objets de la classe Personne" << endl;
  cout << " 3. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
void Essai1()
{
  float nbr;
  cout << "----- 1. Test du template ListeS avec des entiers ------------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeS<float> liste;
  liste.affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et -8..." << endl;
  liste.insere(3.2);
  liste.insere(-2);
  liste.insere(5.6);
  liste.insere(-1);
  liste.insere(0);
  liste.insere(-8);
  liste.affiche();                                       // --> (-8 -2 -1 0 3 5)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  nbr = liste.get(2);
  cout << "nbr : " << nbr << endl;

  nbr = liste.get(3);
  cout << "nbr : " << nbr << endl;

  liste.affiche();

  cout << endl;
}

/*******************************************************************************************************/
void Essai2()
{
  string s1("A");
  string s2("B");
  string s3("C");
  string s4("D");
  string s5("E");
  string s6("F");
  string s7("G");

  cout << "----- 2. Test du template ListeS avec des string ------------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeS<string> liste;
  liste.affiche();                                       
  cout << endl;

  cout << "On insere quelques string..." << endl;
  liste.insere(s1);
  liste.insere(s2);
  liste.insere(s3);
  liste.insere(s4);
  liste.insere(s5);
  liste.insere(s6);
  liste.insere(s7);
  liste.affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  cout << liste.get(2) << endl;
  cout << liste.get(3) << endl;

  liste.affiche();
  cout << endl;
}
