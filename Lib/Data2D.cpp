#include "Data2D.h"

Data2D::Data2D()
{
	setValue1(0);
	setValue2(0);
}

Data2D::Data2D(float v1, float v2)
{
	setValue1(v1);
	setValue2(v2);
}
Data2D::Data2D(const Data2D & D)
{
	setValue1(D.getValue1());
	setValue2(D.getValue2());
}

float Data2D::getValue1() const
{
	return Val1;
}
float Data2D::getValue2() const
{
	return Val2;
}

void Data2D::setValue1(const float v)
{
	Val1 = v;
}
void Data2D::setValue2(const float v)
{
	Val2 = v;
}

int Data2D::Comparaison(const Data2D & D) const
{
	if (this->getValue1() == D.getValue1() && this->getValue2() == D.getValue2())
		return 0;

	return 1; 
}

ostream& operator<<(ostream& s, const Data2D & D)
{
	s << "valeur: " << D.getValue1() << " valeur: " << D.getValue2();
	return s;
}
