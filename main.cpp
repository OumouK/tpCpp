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
    //c.setTour();
    Fantassin f;
    Archer archer;
    Fantassin f2;
    c.creeUnite(&f);
    c.avancer(&f);

    o.creeUnite(&archer);
    o.avancer(&archer);
    while(f.getPosition()!=2){
            c.avancer(&f);
    }
 std::cout<<"taille av delete " <<o.getUnites().size()<<std::endl;
    c.attaquer();
    o.miseAJour();
    std::cout<<"taille ap delete " <<o.getUnites().size()<<std::endl;

    /*c.setTour();
    c.creeUnite(&archer);
    o.setTour();
    o.avancer(&f);
    c.setTour();
    c.avancer(&archer);*/
    a->afficheJeu();
    return 0;
}
