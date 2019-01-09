#ifndef CARCHER_H_INCLUDED
#define CARCHER_H_INCLUDED

#include"cUnite.h"

class Archer : public Unite{
public:
    Archer(): Unite(12, 8, 3){ std::vector<int> v{1,2,3}; m_portee=v;};

};
#endif // UNITE_H_INCLUDED

