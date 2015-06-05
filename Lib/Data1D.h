#ifndef DATA1D_H
#define DATA1D_H

#include "Data.h"
#include <iostream>

using namespace std;

class Data1D : public Data
{
	private:
		float Val; // Xi
		int Eff; // Yi
	public:
		Data1D();
		Data1D(float v, int e);
		Data1D(const Data1D & D);
		~Data1D() {};

		float getValue() const;
		int getEffective() const;

		void setValue(const float v);
		void setEffective(const int e);

		int Comparaison(const Data1D & D) const;

		Data1D operator++(int);
        Data1D& operator++();
		int operator<(const Data1D & D){ return Comparaison(D) == -1; }
		int operator>(const Data1D & D){ return Comparaison(D) == 1; }
		int operator==(const Data1D & D){ return Comparaison(D) == 0; }

		friend ostream& operator<<(ostream &, const Data1D & D);
};

#endif // DATA1D_H
