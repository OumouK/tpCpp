#include <iostream>
#include "cAire.hpp"
#include "cFantassin.hpp"
#include "cArcher.hpp"
#include "cCatapulte.hpp"
#include "cJoueur.hpp"
using namespace std;

int main()
{
    Aire *a=new Aire();

    Joueur o("Oumou",0, a);
    Joueur c("Chloe",11, a);
    //c.setTour();

    Fantassin f;
    Archer archer, archer2;
    Fantassin f2;
    c.creeUnite(&f);
    o.creeUnite(&archer);
    o.creeUnite(&f2);
    o.tour();
    while(f.getPosition()!=2){
           c.avancer(&f);
    }
   //o.avancer(&archer);
c.creeUnite(&archer2);
   c.phase1();
   c.phase2();
   Catapulte cat;
   c.creeUnite(&cat);
   //c.avancer(&f);

   //o.attaquer();
      //o.attaquer();
std::cout<<"taille sesunite avant  "<<o.getUnites().size()<<std::endl;
c.tour();
o.miseAJour();
c.tour();
std::cout<<"taille sesunite "<<o.getUnites().size()<<std::endl;
//c.attaquer();
    //c.avancer(&f2);
    //c.creeUnite(&archer2);
// std::cout<<"taille av delete " <<o.getUnites().size()<<std::endl;

    //o.miseAJour();
   // std::cout<<"taille ap delete " <<o.getUnites().size()<<std::endl;

    /*c.setTour();
    c.creeUnite(&archer);
    o.setTour();
    o.avancer(&f);
    c.setTour();
    c.avancer(&archer);*/
    a->afficheJeu();
    delete(a);
    return 0;
}
