#ifndef DATA_SOURCE_H
#define DATA_SOURCE_H

#include "Fichier.h"
#include "Data.h"
#include "Data1D.h"
#include "Liste.h"
#include "ListeS.h"
#include "ListeTriee.h"
#include "Utils.h"

#include <string>
#include <iostream>


using namespace std;

class DataSource // abstract
{
	protected:
        	string _Nom;
        	string _Sujet ;
        	int _EffTotal;
        	char _Type ;
	public:
        DataSource(Fichier & file, const string Nom, const string Sujet, int type, int col);
        DataSource(const DataSource&);
        virtual ~DataSource();

        string getNom() const { return _Nom; }
        string getSujet() const { return _Sujet; }
        int getEffTotal() const { return _EffTotal; }
        char getType() const { return _Type; }

        void setNom(const string & Nom) { _Nom = string(Nom); }
        void setSujet(const string & Sujet) { _Sujet = string(Sujet); }
        void setEffTotal(const int & total) { _EffTotal = total; }
        void setType(const char & type) { _Type = type; }

	virtual float getXi(int) const = 0;
	virtual float getYi(int) const = 0;
        virtual int getValueCount() const = 0;
        virtual bool isEmpty() const = 0;
        virtual string toString() const = 0;
};

#endif // DATA_SOURCE_H
