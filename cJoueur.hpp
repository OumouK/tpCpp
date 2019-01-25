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
    bool m_tour;
    int m_saBase;
    int pas;

public:
    Joueur(std::string nom,int i, Aire *a): aire(a),m_nom(nom),m_sesPieces(160),m_tour(false),m_saBase(i)
    {
        if(i==0)
        {
            pas=1;
        }
        else
        {
            pas=-1;
        }
    };
    ~Joueur() {/*delete aire;*/}
    bool estTour();
    void setTour();
    void setBase(int c);
    int getBase();
    std::vector<Unite*> getUnites();
    void creeUnite(Unite* u);
    void creeUnite();
    void avancer(Unite* u);
    void phase1();
    void phase2();
    void phase3();
    void miseAJour();
    void initPhase();
    bool tentativeAtt(Unite* u, int n);
    void tour();


};

#endif // JOUEUR_H
