#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include "cUnite.hpp"
#include "cAire.hpp"


class Joueur
{
    Aire *aire;
    std::string m_nom;
    std::vector<Unite*> m_sesUnites;
    int m_sesPieces;
    int m_ptVie;
    bool m_tour;
    int m_saBase;

    public:
        Joueur(std::string nom,int i, Aire *a): aire(a),m_nom(nom),m_sesPieces(16),m_ptVie(100),m_tour(false),m_saBase(i){};
        ~Joueur(){delete aire;}
        bool estTour();
        void setTour();
        void setBase(int c);
        int getBase();
        void creeUnite(Unite* u);
        void avancer(Unite* u);
        void attaquer(Unite* u);


};

#endif // JOUEUR_H
