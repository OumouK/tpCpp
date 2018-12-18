#ifndef CFANTASSIN_H_INCLUDED
#define CFANTASSIN_H_INCLUDED

#include"cUnite.hpp"

class Fantassin : public Unite{

public:
    Fantassin(): Unite(10, 10, 4){ std::vector<int> v{1}; m_portee=v;};

#endif // UNITE_H_INCLUDED

