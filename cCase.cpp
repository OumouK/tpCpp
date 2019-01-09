#include "cCase.h"

bool Case::estOccupee(){
    return m_occupee;
}
void Case::setOccupee(bool b){
   m_occupee=b;
}

void Case::setUnite(Unite u){
    m_sonUnite=u;
}

Unite Case::getUnite(){
    return m_sonUnite;
}
