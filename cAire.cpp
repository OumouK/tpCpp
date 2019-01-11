#include "cAire.hpp"



void Aire::initCases(){

    for(int i=0;i<12;i++){
        Case* c=new Case(i);
        m_sesCases[i]=c;
    }

}

void Aire::afficheJeu(){
    for(int i=0;i<12;i++){
        m_sesCases[i]->afficheCase();

  }
}

Case* Aire::getCase(int i){
    return m_sesCases[i];
}

void Aire::avancer(Unite * u, int pas){
    int posActuelle=u->getPosition(); //case actuelle de l'unite
    int next=posActuelle+pas; //case qu'elle souhaite atteindre
    if(!getCase(next)->estOccupee() && next!=0 && next!=11){ //la case suivante nest pas occupee et n'est pas une base
         getCase(posActuelle)->deleteUnite(); //on supprime l'unite de la case où elle etait
         u->avancer(pas);
         getCase(next)->setUnite(u);
    }
    else{
        std::cout<<"ne peut pas avancer"<<std::endl;
    }
}

