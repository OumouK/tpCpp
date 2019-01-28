#include "cAire.hpp"
#include "cBase.hpp"


//Utilisee pour l'initialisation de l'aire de jeu
void Aire::initCases(int taille){
    Base* b=new Base(10, 0);
    m_sesCases.push_back(b);
    for(int i=1; i<taille-1; i++)
    {
        Case* c=new Case(i);
        m_sesCases.push_back(c);
    }
    Base* b2=new Base(10, taille-1);
    m_sesCases.push_back(b2);
}


//affichage des cases
void Aire::afficheJeu(){
    std::cout<< "\t/*******************************************AGE OF WAR*******************************************/" << std::endl;
    //haut des cases
    std::cout<<"\t";

    for(size_t i=0; i<m_sesCases.size();i++){
            if(i==0 || i==11){
                std::cout<<"|~|___|~|";

            }
            else{
                std::cout<<"_________";
        }
    }

     std::cout<<std::endl<<"\t";
    for(size_t i=0; i<m_sesCases.size();i++){
            if(i==0){
                std::cout<<"|   O   |";

            }else if(i==11){
                std::cout<<"|   X   |";
            }
            else{
                std::cout<<"  ______ ";
            }
    }

    std::cout<<std::endl<<"\t";
    for(size_t i=0;i<m_sesCases.size();i++){
        std::cout<<" |  "<<(i<10?" ":"")<<i<<"  |";

    }
    std::cout<<std::endl<<"\t"<<" ";
    for(size_t i=0;i<m_sesCases.size();i++){
        m_sesCases[i]->afficheCase();

    }
  std::cout<<std::endl<<"\t";

  //bas des cases
  for(size_t i=0; i<m_sesCases.size();i++){
        std::cout<<" |______|";
    }
     std::cout<<std::endl<<"\t";
    for(size_t i=0; i<m_sesCases.size();i++){
        std::cout<<"_________";
    }

}


Case* Aire::getCase(int i){
    return m_sesCases[i];
}

std::vector<Case*> Aire::getSesCases(){
    return m_sesCases;
}

//fonction qui fait avancer une unite dans une direction indiquee par le parametre pas
void Aire::avancer(Unite * u, int pas){
    int posActuelle=u->getPosition(); //case actuelle de l'unite
    int next=posActuelle+pas; //case qu'elle souhaite atteindre
    if(!getCase(next)->estOccupee() && next!=0 && next!=11){ //la case suivante nest pas occupee et n'est pas une base
        std::cout<<"\tL unite situee en case "<<u->getPosition()<<" se rapproche de la base ennemie.\n";
        getCase(posActuelle)->deleteUnite(); //on supprime l'unite de la case où elle etait
        u->avancer(pas);
        getCase(next)->setUnite(u);
    }
    else{
        std::cout<<"\tL unite situee en case "<<u->getPosition()<<" n a pas pu avancer car la case devant elle est deja occupee."<<std::endl;
    }
}
