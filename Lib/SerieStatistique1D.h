#ifndef SERIESTATISTIQUE_H
#define SERIESTATISTIQUE_H

#include "Echantillon.h"
#include "DataSource.h"
#include "DataSourceSerieDiscrete.h"
#include "DataSourceSerieContinue.h"
#include "ListeTriee.h"
#include "Liste.h"

#include <iostream>
#include <math.h>
using namespace std;

enum statType { CONTINUE, DISCRETE };

class SerieStatistique1D {
    private:
        DataSource * data;
        statType type;

        float getXiFromEffectiveNum(int effectiveNum) const;

    public:
        SerieStatistique1D(Echantillon *);
        SerieStatistique1D(const SerieStatistique1D&);
        ~SerieStatistique1D();

        inline float getMinVal() const { return data->getXi(0); }
        inline float getMaxVal() const { return data->getXi(data->getValueCount() - 1); }
        inline float getEtendue() const { return getMaxVal() - getMinVal(); }
        float getMediane() const;
        float getMoyenne() const;
        ListeTriee<float> getModes() const;
        inline float getMode() const { return getModes().get(0); }
        float getVariance() const;
        inline float getEcartType() const { return (float)sqrt(getVariance()); }
        inline float getCoefVariation() const { return (float)((getEcartType() / getMoyenne()) * 100); }
        inline int getTotalEffective() const { return data->getEffTotal(); }
        int getControlState() const;

        void AfficheRapport() const;
};

#endif
