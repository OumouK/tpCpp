#ifndef CASE_H
#define CASE_H

#include "cUnite.h"

class Unite;
class Case
{
    int m_saPosition;
    Unite & m_sonUnite;
    bool m_occupee;
    public:
        Case(int i);
        bool estOccupee();
        void setOccupee(bool b);
        void setUnite(Unite u);
        Unite getUnite();


};

#endif // CASE_H
