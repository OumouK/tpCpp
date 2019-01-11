#include "cJoueur.hpp"
#include <stdlib.h>

void Joueur::setTour(){
    m_tour=true;
    m_sesPieces+=8;
}

bool Joueur::estTour(){
    return m_tour;
}

void Joueur::creeUnite(Unite* u){

    if(!aire->getCase(m_saBase)->estOccupee() && m_sesPieces>u->getPrix()){

        m_sesPieces-=u->getPrix();

        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);

    }


}

void Joueur::setBase(int c){
    m_saBase=c;

}

int Joueur::getBase(){
    return m_saBase;
}

void Joueur::avancer(Unite* u){
    //int pas;
    //if(m_tour){

        /*if(aire->getCase(m_saBase)->getPosition()==0 ){
                pas=1;

        }
        if(aire->getCase(m_saBase)->getPosition()==11){
             std::cout<<"on est la"<<std::endl;
             pas=-1;
        }*/
        aire->avancer(u, pas);

       // }
}

void Joueur::attaquer(){
    //l'unite la plus proche de la base du joueur courant attaque
    int distMax=15;
    Unite * uniteProche=NULL;
    for(Unite * u:m_sesUnites){
            int distActu=std::abs(u->getPosition()-m_saBase);
        if(distActu <distMax){
            distMax=distActu;
            uniteProche=u;
        }
    }
    //uniteProche->attaquer(aire, pas);


if(aire->getCase(uniteProche->getPosition()+pas)->estOccupee()){
        std::cout<<"j'attaque "<<uniteProche->getPosition()<<std::endl;
        Unite* ptr_ennemi=aire->getCase(uniteProche->getPosition()+pas)->getUnite();
        ptr_ennemi->setPtV(ptr_ennemi->getPtV()-2*uniteProche->getPtAt());

        if(ptr_ennemi->getPtV()<=0){

            aire->getCase(ptr_ennemi->getPosition())->deleteUnite();

            //delete ptr_ennemi;
        }
}


}

void Joueur::miseAJour(){

    for(size_t i=0;i<m_sesUnites.size();i++){
         if(m_sesUnites[i]->getPtV()<=0){
            m_sesUnites.erase(m_sesUnites.begin()+i);
        }
    }
}

std::vector<Unite*> Joueur::getUnites(){
    return m_sesUnites;
}
