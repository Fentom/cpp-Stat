#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include <string>

using namespace std;

template <class Type> struct Noeud 
{ 
	Type * valeur; 
	Noeud<Type> * pSuivant; 
};

template <class Type> class Iterateur;

template<class Type>
class Liste
{
	protected:
		Noeud<Type> * pTete;
		Noeud<Type> * getNode(const int) const;
	public:
		Liste();
		Liste(const Liste<Type> & l);
		~Liste();

		const bool vide() const;
		virtual inline Type & get(const int index) const { return *(getNode(index)->valeur); };
		const int getNombreElements() const;
		void affiche() const;

		virtual void insere(const Type & val);

		friend class Iterateur<Type>; // to do
};


#endif // LISTE_H
