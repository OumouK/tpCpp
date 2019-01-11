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
    std::cout<<"on a mis l'unite"<<m_occupee<<std::endl;
    ptr_sonUnite=u;
    u->setPosition(m_saPosition);
    m_occupee=true;
    std::cout<<"on a mis l'unite"<<m_occupee<<std::endl;

}

void Case::deleteUnite(){
    ptr_sonUnite=NULL;
    m_occupee=false;
}

Unite* Case::getUnite(){
    return ptr_sonUnite;
}

void Case::afficheCase(){

    std::cout << "Case "<< m_saPosition<<": ";
    if(m_occupee){
        std::cout << "Case occupee ";
        ptr_sonUnite->affiche();
    }
}
