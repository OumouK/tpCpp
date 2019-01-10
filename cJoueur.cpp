#include "cJoueur.hpp"

void Joueur::setTour(){
    m_tour=true;
    m_sesPieces+=8;
}

bool Joueur::estTour(){
    return m_tour;
}

void Joueur::creeUnite(Unite u){
    if(!m_saBase.estOccupee() && m_sesPieces>u.getPrix()){
        m_sesPieces-=u.getPrix();
        m_sesUnites.push_back(u);
        aire->getCase(m_saBase.getPosition()).setUnite(&u);
    }


}

void Joueur::setBase(Case c){
    m_saBase=c;

}

Case Joueur::getBase(){
    return m_saBase;
}

void Joueur::avancer(Unite u){
    if(m_saBase.getPosition()==0){
       u.avancer(1);
    }
    if(m_saBase.getPosition()==11){
       u.avancer(-1);
    }
}
