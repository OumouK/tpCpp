#include "cJoueur.hpp"
#include "cFantassin.hpp"
#include "cCatapulte.hpp"
#include "cArcher.hpp"
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
        u->setBase(m_saBase);

    }
}

void Joueur::creeUnite(/*Unite* u*/){ //Pour le mode IA
    Unite * u=NULL;
    if(!aire->getCase(m_saBase)->estOccupee()){
        if(m_sesPieces<10){
            return; //on ne peut rien creer
        }
        if(m_sesPieces<12){
            u=new Fantassin;
        }
        else if(m_sesPieces<20){
            u=new Archer;
        }
        else {
            u=new Catapulte;
        }
        m_sesPieces-=u->getPrix();

        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);
        u->setBase(m_saBase);
    }



}

void Joueur::setBase(int c){
    m_saBase=c;

}

int Joueur::getBase(){
    return m_saBase;
}

void Joueur::avancer(Unite* u){

        aire->avancer(u, pas);
        //ordonne();

}

void Joueur::phase2(){
   /* size_t cpt=0;
    while(cpt<m_sesUnites.size()){ //toutes les nités nont pas attaquer
        Unite * uniteLoin=NULL;
        int distMin=-1;
        for(Unite * u:m_sesUnites){
        int distActu=std::abs(u->getPosition()-m_saBase);
        if(distActu>distMin && !u->getAttaque()){
           distMin=distActu;
           uniteLoin=u;

        }
        }
        uniteLoin->setAttaque(true);
       if(uniteLoin->getType()!="Catapulte"){
            aire->avancer(uniteLoin, pas);
            std::cout<<"AVAAANCE"<<uniteLoin->getPosition()<<std::endl;

       }else{
        std::cout<<"CATAPULTE"<<std::endl;
       }



        cpt++;
        }
        initPhase();

       // ordonne();
*/

       for(int i=m_saBase+11*pas; i!=m_saBase-pas;i-=pas){
            Case* caseActu=aire->getCase(i);
            if(caseActu->estOccupee() && caseActu->getUnite()->getBase()==m_saBase){
                Unite * uniteActu=caseActu->getUnite();

                if(uniteActu->getType()!="Catapulte"){
                aire->avancer(uniteActu, pas);
                std::cout<<"AVAAANCE"<<uniteActu->getPosition()<<std::endl;

               }else{
                std::cout<<"CATAPULTE"<<std::endl;
               }
            }
       }


}

void Joueur::phase3(){
     for(int i=m_saBase+11*pas; i!=m_saBase-pas;i-=pas){ // On part de la case la plus lointaine comme en phase 2
            Case* caseActu=aire->getCase(i);
            //bool succes=false;
            if(caseActu->estOccupee() && caseActu->getUnite()->getBase()==m_saBase){
                Unite * uniteActu=caseActu->getUnite();

                if(uniteActu->getType()=="Catapulte" && !uniteActu->getAttaque()){
                aire->avancer(uniteActu, pas);
                std::cout<<"AVAAANCE"<<uniteActu->getPosition()<<std::endl;

               }else if(uniteActu->getType()=="Fantassin" && !uniteActu->getAttaque()){ //Fantassin qui n'a pas pu attaquer
                    /*succes=*/tentativeAtt(uniteActu, 1);
               }else if(uniteActu->getType()=="Super-soldat"){ //Fantassin qui n'a pas pu attaquer
                   /* succes=*/tentativeAtt(uniteActu, 1);
               }

            }
       }
}

void Joueur::initPhase(){
    for(Unite* u:m_sesUnites){
        u->setAttaque(false);
    }
}

/*void Joueur::ordonneProche(){
    size_t cpt=0;
    while(m_sesUnites.size()!=0){ //toutes les nités nont pas attaquer
    Unite * uniteProche=NULL;
    int distMax=15;
    for(int i=0;i<m_sesUnites.size();i++){
        int distActu=std::abs(u->getPosition()-m_saBase);
        if(distActu <distMax){
            distMax=distActu;
            //u->setAttaque(true);
            uniteProche=u;


        }
    }
}
}*/

void Joueur::attaquer(){
    //l'unite la plus proche de la base du joueur courant attaque

    /*size_t cpt=0;
    while(cpt<m_sesUnites.size()){ //toutes les nités nont pas attaquer
    Unite * uniteProche=NULL;
    int distMax=15;
    for(Unite * u:m_sesUnites){
        int distActu=std::abs(u->getPosition()-m_saBase);
        if(distActu <distMax && !u->getAttaque()){
            distMax=distActu;
            //u->setAttaque(true);
            uniteProche=u;

        }
    }
    uniteProche->setAttaque(true);
    //uniteProche->attaquer(aire, pas);
std::cout<<"test j'attaque "<<uniteProche->getPosition()<<std::endl;
 //pour dire s'il a tenter d'attaquer
int n=1;
bool succes=false;
while(n<=uniteProche->getNbEssais() && !succes){
  std::string typeUnite=uniteProche->getType();
  if(typeUnite!="Catapulte"){
    succes=tentativeAtt(uniteProche, n);
  }
  n+=1;

}

        cpt++;
    }*/
//if(m_saBase==0){
        for(int i=m_saBase; i!=m_saBase+pas*11;i+=pas){
            Case* caseActu=aire->getCase(i);
            std::cout<<"JATTAQUE"<<std::endl;
        if(caseActu->estOccupee() && caseActu->getUnite()->getBase()==m_saBase){
            Unite* uniteActu=caseActu->getUnite();
            int n=1;
            bool succes=false;
            while(n<=uniteActu->getNbEssais() || !succes){
              std::string typeUnite=uniteActu->getType();

              if(typeUnite=="Catapulte"){
                 succes=tentativeAtt(uniteActu, n+1);
              }
              else{
                succes=tentativeAtt(uniteActu, n);
              }
              n+=1;

            }
        }

    }

//}else{
    /*for(int i=m_saBase; i>0;i+=pas){
            Case* caseActu=aire->getCase(i);
            std::cout<<"JATTAQUE"<<std::endl;
        if(caseActu->estOccupee() && caseActu->getUnite()->getBase()==m_saBase){
            Unite* uniteActu=caseActu->getUnite();
            int n=1;
            bool succes=false;
            while(n<=uniteActu->getNbEssais() || !succes){
              std::string typeUnite=uniteActu->getType();
              if(typeUnite!="Catapulte"){
                succes=tentativeAtt(uniteActu, n);
              }
              n+=1;

            }
        }

}



}*/
}

bool Joueur::tentativeAtt(Unite* u, int n){

if(aire->getCase(u->getPosition()+pas*n)->estOccupee() && aire->getCase(u->getPosition()+pas*n)->getUnite()->getBase()!=m_saBase){
            std::cout<<"j'attaque "<<u->getPosition()<<std::endl;
            Unite* ptr_ennemi=aire->getCase(u->getPosition()+pas*n)->getUnite();
            //Il ne s'attaque pas lui meme

            ptr_ennemi->setPtV(ptr_ennemi->getPtV()-2*u->getPtAt());

            if(ptr_ennemi->getPtV()<=0){

                aire->getCase(ptr_ennemi->getPosition())->deleteUnite();

                //delete ptr_ennemi;
            }

            if(u->getType()=="Catapulte"){
                    int autreCase;
                    if(n<3){
                            autreCase=(n+1);

                    }else{
                    autreCase=n-1;
                    }
                    if(aire->getCase(u->getPosition()+pas*n)->estOccupee()){
                       Unite* ptr_ennemi2=aire->getCase(u->getPosition()+pas*autreCase)->getUnite();
                 ptr_ennemi2->setPtV(ptr_ennemi2->getPtV()-2*u->getPtAt());

            if(ptr_ennemi2->getPtV()<=0){

                aire->getCase(ptr_ennemi2->getPosition())->deleteUnite();

                //delete ptr_ennemi;
            }


            }

                       }
    u->setAttaque(true);
            return true;
        }
        //personne sur la case donc pas attaquer
        u->setAttaque(false); //pas forcement utile
        return false;
}

void Joueur::miseAJour(){

    for(size_t i=0;i<m_sesUnites.size();i++){
         if(m_sesUnites[i]->getPtV()<=0){
            m_sesUnites.erase(m_sesUnites.begin()+i);
        }
    }
}



/*void  Joueur::ordonne(){
    std::vector<Unite*> ordonne;
    for(Unite* u:m_sesUnites){

    }
}*/

std::vector<Unite*> Joueur::getUnites(){
    return m_sesUnites;
}
