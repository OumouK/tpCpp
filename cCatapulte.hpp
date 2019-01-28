#ifndef CCATAPULTE_H_INCLUDED
#define CCATAPULTE_H_INCLUDED

#include "cUnite.hpp"

class Catapulte : public Unite{
public:
    Catapulte(): Unite(20, 12, 6,"Catapulte", 3){};
    void aff();

};
#endif // UNITE_H_INCLUDED

