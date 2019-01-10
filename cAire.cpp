#include "cAire.hpp"



void Aire::initCases(){

    for(int i=0;i<12;i++){
        m_sesCases[i].setPosition(i);
    }

}

void Aire::afficheJeu(){
    for(int i=0;i<12;i++){
        m_sesCases[i].afficheCase();

  }
}

Case Aire::getCase(int i){
    return m_sesCases[i];
}
/*
void Aire::creeUnite(Joueur j,Unite u){
    if(!j.getBase().estOccupee()){
        if(j.creeUnite(u)){
            m_sesCases[j.getBase().getPosition()].setUnite(&u);
        }

    }
}

void Aire::avancer(Joueur j, Unite u){


}*/

