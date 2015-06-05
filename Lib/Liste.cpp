#include "Liste.h"

#include <iostream>
#include <string>

using namespace std;

template<class Type>
Liste<Type>::Liste()
{
	pTete = NULL;
}

template<class Type>
Liste<Type>::Liste(const Liste<Type> & l)
{
	Noeud<Type> *pCur, *pPrec;

	pCur = this->pTete;

	while(pCur != NULL)
	{
		pPrec = pCur;
		pCur = pCur->pSuivant;

		delete pPrec;
	}
	
	for (int i = 0; i < l.getNombreElements(); ++i)
	{
		this->insere(l.get(i));
	}
}

template<class Type>
Liste<Type>::~Liste()
{
	Noeud<Type> *pCur, *pPrec;

	pCur = pTete;

	while(pCur != NULL)
	{
		pPrec = pCur;
		pCur = pCur->pSuivant;

		delete pPrec;
	}
}

template<class Type>
void Liste<Type>::insere(const Type & val)
{
	Noeud<Type> *pCur = this->pTete;

	if(pCur == NULL)
	{
		this->pTete = new Noeud<Type>;
		this->pTete->valeur = new Type(val);
	}
	else
	{
		while(pCur->pSuivant != NULL)
		{
			pCur = pCur->pSuivant;
		}

		pCur->pSuivant = new Noeud<Type>;
		pCur->pSuivant->valeur = new Type(val);
	}
}

template<class Type>
Noeud<Type> * Liste<Type>::getNode(const int index) const 
{
    if (index >= getNombreElements())
    	return NULL;

    Noeud<Type> * tmp = pTete;

    for(int i = 0; i < index; ++i)
        tmp = tmp->pSuivant;

    return tmp;
}

template<class Type>
const bool Liste<Type>::vide() const
{
	if (pTete == NULL)
		return 1;
	else 
		return -1;
}

template<class Type>
const int Liste<Type>::getNombreElements() const
{
	Noeud<Type> *pCur;
	int i = 0;

	pCur = pTete;

	while(pCur != NULL)
	{
		i++;
		pCur = pCur->pSuivant;
	}

	return i;
}
template<class Type>
void Liste<Type>::affiche() const
{
	Noeud<Type> *pCur;
	int i = 0;

	pCur = pTete;
	if (pCur == NULL)
		cout << "La liste est vide." << endl;
	else
	{
		while(pCur != NULL)
		{
			cout << "indice [" << i << "] = " << *pCur->valeur << endl;
			pCur = pCur->pSuivant;
			i++;
		}
	}
}

template class Liste<int>;
template class Liste<float>;
template class Liste<string>;

#include "Data.h"
template class Liste<Data>;

#include "Data1D.h"
template class Liste<Data1D>;

#include "Data2D.h"
template class Liste<Data2D>;
