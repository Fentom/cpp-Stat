#ifndef LISTE_S_H
#define LISTE_S_H

#include "Liste.h"
#include <iostream>

using namespace std;

template<class Type>
class ListeS : public Liste<Type>
{
	private:
	public:
		void insere(const Type & val);
};




#endif // LISTE_S_H
