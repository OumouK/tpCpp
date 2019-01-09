#ifndef JEU_H
#define JEU_H


#include "cJoueur.hpp"


class Jeu
{
    Joueur m_a;
    Joueur m_b;
    Case m_sesCases[12];


    public:
        Jeu(Joueur a, Joueur b):m_a(a),m_b(b){};
        virtual ~Jeu();
};

#endif // JEU_H

