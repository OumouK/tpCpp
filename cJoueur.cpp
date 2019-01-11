#include "cJoueur.hpp"

void Joueur::setTour(){
    m_tour=true;
    m_sesPieces+=8;
}

bool Joueur::estTour(){
    return m_tour;
}

void Joueur::creeUnite(Unite* u){

    if(!aire->getCase(m_saBase)->estOccupee() && m_sesPieces>u->getPrix()){
            std::cout<<"Joueur cree lunite"<<std::endl;
        m_sesPieces-=u->getPrix();

        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);
        std::cout<<aire->getCase(m_saBase)->estOccupee()<<std::endl;
    }


}

void Joueur::setBase(int c){
    m_saBase=c;

}

int Joueur::getBase(){
    return m_saBase;
}

void Joueur::avancer(Unite* u){
    int pas;
    if(m_tour){
            std::cout<<"cest son tour"<<std::endl;
        if(aire->getCase(m_saBase)->getPosition()==0 ){
                pas=1;

        }
        if(aire->getCase(m_saBase)->getPosition()==11){
             std::cout<<"on est la"<<std::endl;
             pas=-1;
        }
        aire->avancer(u, pas);

        }
}

void Joueur::attaquer(Unite* u){


}
