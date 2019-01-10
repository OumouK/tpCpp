#include <iostream>
#include "cAire.hpp"
#include "cFantassin.hpp"
#include "cJoueur.hpp"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Aire *a=new Aire();

    Joueur o("Oumou",0, a);
    Joueur c("Chloe",11, a);

    Fantassin f;
    o.creeUnite(f);
    a->afficheJeu();
    return 0;
}
