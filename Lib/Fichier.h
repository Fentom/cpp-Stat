#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>
#include <string>
#include <fstream>

#include "ListeS.h"

using namespace std;

class Fichier 
{
    private:
        string NameFile;
        ifstream stream;
    public:
        Fichier(const string nom);
        Fichier(Fichier & f);
        ~Fichier();

        ifstream getStream() const;

        inline bool isOpen() { return stream.is_open(); }
        inline bool end() { return stream.peek() == EOF; }
        string readLine();
        ListeS<string> readLine(char splitchar);
        ListeS<string> readLines();
};

#endif
