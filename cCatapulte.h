#ifndef CCATAPULTE_H_INCLUDED
#define CCATAPULTE_H_INCLUDED

#include "cUnite.h"

class Catapulte : public Unite{
public:
    Catapulte(): Unite(20, 12, 6){ std::vector<int> v{2,3}; m_portee=v;};

};
#endif // UNITE_H_INCLUDED

