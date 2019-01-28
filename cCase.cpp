#include "cCase.hpp"
#include "cUnite.hpp"


Case::~Case(){
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
    u->setPosition(m_saPosition);
    m_occupee=true;


}

void Case::deleteUnite(){
    ptr_sonUnite=NULL;
    m_occupee=false;
}

Unite* Case::getUnite(){
    return ptr_sonUnite;
}



void Case::afficheCase(){

    if(m_occupee){
        //on affiche son unite
        std::cout<<"|  ";
        ptr_sonUnite->aff();
        std::cout<<((ptr_sonUnite->getBase()==0)?"o":"x")<<"  | ";

    }else{
        std::cout<<"|      | "; //case vide
    }
}
