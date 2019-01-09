#include "cCase.hpp"
#include "cUnite.hpp"

bool Case::estOccupee(){
    return m_occupee;
}
void Case::setOccupee(bool b){
   m_occupee=b;
}

void Case::setUnite(Unite * u){
    ptr_sonUnite=u;
}

Unite* Case::getUnite(){
    return ptr_sonUnite;
}
