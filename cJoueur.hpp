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
    bool m_victoire;
    int m_saBase;
    int pas;

    public:
        Joueur(std::string nom,int i, Aire *a): aire(a),m_nom(nom),m_sesPieces(8),m_ptVie(100),m_victoire(false),m_saBase(i){ if(i==0) {pas=1;} else{
        pas=-1;}};
        ~Joueur(){/*delete aire;*/}
        bool estGagnant();
        void setGagnant();
        std::string getNom();
        int getBase();
        int getPieces();
        std::vector<Unite*> getUnites();
        void creeUnite(Unite* u);
        void creeUnite();
        void phase2();
        void phase3();
        void phase1();
        void miseAJour();
        void initPhase();
        void tentativeAtt(Unite* u, int n);
        void tour(Joueur * ennemi);
        void affiche();
        void affiche(Joueur * ennemi);
        void demandeCreationUnite();




};

#endif // JOUEUR_H
