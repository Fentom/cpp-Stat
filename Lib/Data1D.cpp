#include "Data1D.h"

using namespace std;

Data1D::Data1D()
{
	setValue(0);
	setEffective(0);
}

Data1D::Data1D(float v, int e)
{
	setValue(v);
	setEffective(e);
}

Data1D::Data1D(const Data1D & D)
{
	setValue(D.getValue());
	setEffective(D.getEffective());
}

float Data1D::getValue() const
{
	return Val;
}

int Data1D::getEffective() const
{
	return Eff;
}

void Data1D::setValue(const float v)
{
	Val = v;
}

void Data1D::setEffective(const int e)
{
	Eff = e;
}

Data1D Data1D::operator++(int)
{
    Data1D tmp(*this);
    ++*this;
    return tmp;
}

Data1D& Data1D::operator++()
{
    setEffective(getEffective() + 1);
    return *this;
}

int Data1D::Comparaison(const Data1D & D) const
{
	if (this->getValue() < D.getValue())
		return -1;

	if(this->getValue() > D.getValue())
		return 1;

	return 0;
}

ostream& operator<<(ostream& s, const Data1D & D)
{
	s << "valeur: " << D.getValue() << " effectif: " << D.getEffective();
	return s;
}
