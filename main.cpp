#include <iostream>
#include "cAire.hpp"
#include "cFantassin.hpp"
#include "cArcher.hpp"
#include "cJoueur.hpp"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Aire *a=new Aire();
    
    Joueur o("Oumou",0, a);
    Joueur c("Chloe",11, a);
    Fantassin f;
    Archer archer;
    o.creeUnite(&f);
    c.setTour();
    c.creeUnite(&archer);
    o.setTour();
    o.avancer(&f);
    c.setTour();
    c.avancer(&archer);
    a->afficheJeu();
    
       delete a;
    cout << "bonjour" << endl;
    return 0;
}
