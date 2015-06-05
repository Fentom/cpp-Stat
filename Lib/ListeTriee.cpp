#include "ListeTriee.h"

template<class Type>
void ListeTriee<Type>::insere(const Type & val)
{
	Noeud<Type> *pParc = this->pTete;
	Noeud<Type> *pPrec = NULL;
	Noeud<Type> *pTemp = NULL;

	if(pParc == NULL)
	{
		this->pTete = new Noeud<Type>;
		this->pTete->valeur = new Type(val);
		this->pTete->pSuivant = NULL;
	}
	else
	{
		while (pParc != NULL && *pParc->valeur < val)
		{
			pPrec = pParc;
			pParc = pParc->pSuivant;
		}

		if (pPrec == NULL) // AJout en début de liste
		{
			pTemp = this->pTete;
			this->pTete = new Noeud<Type>;
			this->pTete->valeur = new Type(val);
			this->pTete->pSuivant = pTemp;
		}
		else
		{
			pPrec->pSuivant = new Noeud<Type>;
			pPrec->pSuivant->valeur = new Type(val);
			pPrec->pSuivant->pSuivant = pParc;
		}
	}
}
template class ListeTriee<int>;
template class ListeTriee<float>;

#include <string>
using namespace std;
template class ListeTriee<string>;

#include "Data1D.h"
template class ListeTriee<Data1D>;
