#ifndef CBASE_H
#define CBASE_H

#include "cCase.hpp"
#include "cJoueur.hpp"

class Base : public Case
{
    Joueur m_sonJoueur;
    public:
        Base(int i, Joueur j): Case(i),m_sonJoueur(j){};


};

#endif // CBASE_H

