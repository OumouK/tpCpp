#include "cCase.hpp"
#include "cUnite.hpp"


Case::~Case(){
    delete ptr_sonUnite;
}

bool Case::estOccupee(){
    return m_occupee;
}
void Case::setOccupee(bool b){
   m_occupee=b;
}

int Case::getPosition(){
    return m_saPosition;
}
void Case::setPosition(int p){
   m_saPosition=p;
}

void Case::setUnite(Unite * u){
    ptr_sonUnite=u;
    m_occupee=true;
}

Unite* Case::getUnite(){
    return ptr_sonUnite;
}

void Case::afficheCase(){

    std::cout << "Case "<< m_saPosition<<": ";
    if(m_occupee){
        ptr_sonUnite->affiche();
    }
}
