#ifndef LISTE_TRIEE_H
#define LISTE_TRIEE_H

#include "Liste.h"
#include <iostream>

using namespace std;

template<class Type>
class ListeTriee : public Liste<Type>
{
	private:
	public:
		void insere(const Type & val);
};


#endif // LISTE_TRIEE_H
