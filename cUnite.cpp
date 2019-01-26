#include "cCase.hpp"
#include "cUnite.hpp"


int Unite::getPrix(){
    return m_prix;
}

std::string Unite::getType(){
    return m_sonType;
}

int Unite::getPosition(){
    return m_position;
}
int Unite::getPtV(){
    return m_pointVie;
}
int Unite::getPtAt(){
    return m_pointAttaque;
}

int Unite::getNbEssais(){
    return m_nbEssais;
}


void Unite::setPrix(int p){
    m_prix=p;
}

void Unite::setPtV(int p){
    m_pointVie=p;
}

void Unite::setPtAt(int p){
    m_pointAttaque=p;
}
void Unite::setPosition(int p){
    m_position=p;
}

void Unite::setBase(int b){
    m_base=b;
}

int Unite::getBase(){
    return m_base;
}

void Unite::affiche(){
    std::cout <<"\t"<< m_sonType <<" : \n\t\tCase "<<m_position<<"\n\t\tPoints de vie restants : "<<m_pointVie << std::endl;

}

void Unite::avancer(int p){
    m_position+=p;
}

void Unite::setAttaque(bool b){
    attaque=b;

}

void Unite::setType(std::string t){
    m_sonType=t;
}

bool Unite::getAttaque(){
    return attaque;
}

/*void Unite::attaquer(Aire * a, int pas){
std::cout<<"j'attaque "<<m_position<<std::endl;
if(a[m_position+pas]->estOccupee()){
        Unite* ptr_ennemi=a[m_position+pas]->getUnite();
        ptr_ennemi->setPtV(ptr_ennemi->getPtV()-m_pointAttaque);
        if(ptr_ennemi->getPtV()<=0){
            delete ptr_ennemi;
        }
}

}*/



