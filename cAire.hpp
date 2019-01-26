#ifndef JEU_H
#define JEU_H

#include <vector>
#include "cCase.hpp"
#include "cBase.hpp"

class Aire
{
    std::vector<Case*> m_sesCases;

    public:
        Aire(){initCases();}
        Case* getCase(int i);
        std::vector<Case*> getSesCases();
        void initCases();
        void afficheJeu();
        void afficheJoueur();
        void affiche();
        void avancer(Unite* u, int pas);

};

#endif // JEU_H

