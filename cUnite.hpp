#ifndef CUNITE_H_INCLUDED
#define CUNITE_H_INCLUDED

#include <vector>
#include <iostream>
#include "cCase.hpp"

class Case;


class Unite{

protected:
    int m_prix;
    int m_pointVie;
    int m_pointAttaque;
    int m_position;
    std::string m_sonType;
    std::vector<int> m_portee; //A VOIR
    //Joueur m_sonJoueur;

public:
    Unite():m_prix(0),m_pointVie(0),m_pointAttaque(0),m_position(0),m_sonType("Unite"),m_portee({0}){}/*{ m_portee= {0};}*/;
    Unite(int p, int ptV, int ptAt, std::string type):m_prix(p),m_pointVie(ptV), m_pointAttaque(ptAt),m_position(-1), m_sonType(type),m_portee({0}){};
    int getPrix();
    int getPtV();
    int getPtAt();
    int getPosition();
    void setPrix(int p);
    void setPtV(int p);
    void setPtAt(int p);
    void setPosition(int p);
    std::vector<int> getPortee();
    void attaquer();
    void avancer(int p);
    void affiche();
};

#endif // UNITE_H_INCLUDED

