#ifndef CBASE_H
#define CBASE_H

#include "cCase.hpp"

class Base : public Case
{
    int m_pointVie;
public:
    Base(int pt, int i): Case(i), m_pointVie(pt) {};
    ~Base(){};
    int getPtV();
    void setPtV(int p);

};

#endif // CBASE_H
