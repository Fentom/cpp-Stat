#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Utils
{
	public:
		static inline string float2string(float f) {ostringstream os; os << f; return os.str();}
};


#endif // UTILS_H

