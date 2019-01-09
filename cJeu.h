#ifndef JEU_H
#define JEU_H

//Modelise une aire de jeu
#include "cJoueur.h"


class Jeu
{
    Joueur m_a;
    Joueur m_b;
    Case m_sesCases[12];


    public:
        Jeu(Joueur a, Joueur b):m_a(a),m_b(b){m_sesCases[0]=new Base(a);m_sesCases[11]=new Base(b);};
        virtual ~Jeu();
};

#endif // JEU_H

