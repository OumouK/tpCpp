#include "cCase.hpp"
#include "cUnite.hpp"


int Unite::getPrix(){
    return m_prix;
}
int Unite::getPtV(){
    return m_pointVie;
}
int Unite::getPtAt(){
    return m_pointAttaque;
}

std::vector<int> Unite::getPortee(){
    return m_portee;
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

void Unite::affiche(){
    std::cout << m_sonType << std::endl;

}

void Unite::avancer(int p){
    m_position+=p;
}


