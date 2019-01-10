#ifndef JEU_H
#define JEU_H

#include "cCase.hpp"

class Aire
{
   // Joueur m_a;
    //Joueur m_b;
    Case m_sesCases[12];


    public:
        //TODO: aire avec un seul joueur et lautre cest lordi
        //Aire(Joueur a, Joueur b):m_a(a),m_b(b){initCases();};
        Aire(){initCases();}
        Case getCase(int i);
        void initCases();
        void afficheJeu();
        //void creeUnite(Joueur j, Unite u);


};

#endif // JEU_H

