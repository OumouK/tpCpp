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

void Unite::setType(std::string s){
m_sonType=s;
}

int Unite::getBase(){
    return m_base;
}

void Unite::affiche(){
    std::cout << m_sonType << std::endl;

}

void Unite::avancer(int p){
    m_position+=p;
}

void Unite::setAttaque(bool b){
    attaque=b;

}

bool Unite::getAttaque(){
    return attaque;
}




