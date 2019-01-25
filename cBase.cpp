#include "cBase.hpp"

void Base::afficheCase()
{
    if(this->getPosition() == 0){
    std::cout << "Base du 1er Joueur: ";
    } else {
        std::cout << "Base du 2eme Joueur: ";
    }
    if(m_occupee)
    {
        std::cout << "Base occupee ";
        ptr_sonUnite->affiche();
    }
}
int Base::getPtV(){
    return m_pointVie;
}

void Base::setPtV(int p){
    m_pointVie=p;
}
