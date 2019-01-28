#ifndef CUNITE_H_INCLUDED
#define CUNITE_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include "cCase.hpp"


class Case;


class Unite{

protected:
    int m_prix;
    int m_pointVie;
    int m_pointAttaque;
    int m_position;
    int m_base;
    std::string m_sonType;
    bool attaque; //dire si l'unite a attaque ou pas
    int m_nbEssais;

public:
    Unite():m_prix(0),m_pointVie(0),m_pointAttaque(0),m_position(0),m_base(0),m_sonType("Unite"),attaque(false), m_nbEssais(0){};
    Unite(int p, int ptV, int ptAt, std::string type, int n):m_prix(p),m_pointVie(ptV), m_pointAttaque(ptAt),m_position(-1),m_base(-1), m_sonType(type), attaque(false), m_nbEssais(n){};
    int getPrix();
    int getPtAt();
    int getPtV();
    int getPosition();
    int getBase();
    int getNbEssais();
    std::string getType();
    void setType(std::string t);
    void setPrix(int p);
    void setPtV(int p);
    void setPtAt(int p);
    void setPosition(int p);
    void setBase(int b);
    void setAttaque(bool b);
    bool getAttaque();
    void avancer(int p);
    void affiche();
    virtual void aff()=0;
};

#endif // UNITE_H_INCLUDED

