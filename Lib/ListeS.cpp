#include "ListeS.h"
#include <iostream>

using namespace std;

template<class Type>
void ListeS<Type>::insere(const Type & val)
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
template class ListeS<float>;
template class ListeS<int>;

#include <string>
template class ListeS<string>;

#include "Data.h"
template class ListeS<Data>;

#include "Data1D.h"
template class ListeS<Data1D>;

#include "Data2D.h"
template class ListeS<Data2D>;
