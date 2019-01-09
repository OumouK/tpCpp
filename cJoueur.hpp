#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include "cUnite.hpp"


class Joueur
{
    std::string m_nom;
    std::vector<Unite> m_sesUnites;
    int m_sesPieces;

    public:
        Joueur(std::string nom):m_nom(nom),m_sesPieces(8){};


};

#endif // JOUEUR_H
