#ifndef CCATAPULTE_H_INCLUDED
#define CCATAPULTE_H_INCLUDED

#include "cUnite.hpp"

class Catapulte : public Unite{
public:
    Catapulte(): Unite(20, 12, 6,"Catapulte"){ std::vector<int> v{2,3}; m_portee=v;};

};
#endif // UNITE_H_INCLUDED

