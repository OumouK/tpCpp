#ifndef CUNITE_H_INCLUDED
#define CUNITE_H_INCLUDED

#include <vector>

class Unite{
    int m_prix;
    int m_pointVie;
    int m_pointAttaque;
protected:
    std::vector<int> m_portee; //A VOIR

public:
    Unite(int p, int ptV, int ptAt):m_prix(p),m_pointVie(ptV), m_pointAttaque(ptAt){ m_portee= {0};};
};

#endif // UNITE_H_INCLUDED
