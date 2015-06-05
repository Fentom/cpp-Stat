#ifndef DATA2D_H
#define DATA2D_H

#include "Data.h"
#include <iostream>

using namespace std;

class Data2D : public Data
{
	private:
		float Val1; // Xi
		float Val2; // Yi
	public:
		Data2D();
		Data2D(float v1, float v2);
		Data2D(const Data2D & D);
		~Data2D() {};

		float getValue1() const;
		float getValue2() const;

		void setValue1(const float v);
		void setValue2(const float v);

		int Comparaison(const Data2D & D) const;

		int operator==(const Data2D & D){ return Comparaison(D) == 0; }

		friend ostream& operator<<(ostream &, const Data2D & D);
};

#endif // DATA2D_H
