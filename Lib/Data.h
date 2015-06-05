#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data 
{
    public:
        Data() {};
        Data(const Data & D) {};
        virtual ~Data() {};

        friend ostream& operator<<(ostream&, const Data & D);
};

#endif // DATA_H
