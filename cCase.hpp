#ifndef CASE_H
#define CASE_H

#include <iostream>
#include "cUnite.hpp"


class Unite;

class Case
{
protected :
    int m_saPosition;
    Unite* ptr_sonUnite;
    bool m_occupee;
public:
    Case():m_saPosition(-1),ptr_sonUnite(NULL),m_occupee(false) {};
    ~Case();
    Case(int i):m_saPosition(i),ptr_sonUnite(NULL),m_occupee(false) {};
    bool estOccupee();
    void setOccupee(bool b);
    int getPosition();
    void setPosition(int p);
    void setUnite(Unite* u);
    void deleteUnite();
    Unite* getUnite();
    virtual void afficheCase();


};

#endif // CASE_H
