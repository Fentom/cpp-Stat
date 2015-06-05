#ifndef SerieStatistique2D_H
#define SerieStatistique2D_H

#include "DataSource2D.h"
#include "Echantillon.h"

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class SerieStatistique2D {
    private:
        DataSource2D *data;
        
        int Menu() const;
    public:
        SerieStatistique2D(Echantillon *);
        SerieStatistique2D(const SerieStatistique2D&);
        ~SerieStatistique2D();

        float getMoyVal1() const;
        float getMoyVal2() const;
        float getCorrelation() const;
        float getA() const;
        float getB() const;

        void AfficheRapport() const;
        void Previsions() const;
};

#endif
