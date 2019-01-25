#ifndef AIRE_H
#define AIRE_H

#include <vector>
#include "cCase.hpp"
#include "cBase.hpp"
class Aire
{
    std::vector<Case*> m_sesCases;
public:
    //TODO: aire avec un seul joueur et lautre cest lordi
    //Aire(Joueur a, Joueur b):m_a(a),m_b(b){initCases();};
    Aire()
    {
        initCases();
    }
    Case* getCase(int i);
    std::vector<Case*> getSesCases();
    void initCases();
    void afficheJeu();
    void avancer(Unite* u, int pas);

};

#endif // AIRE_H

