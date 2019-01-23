#include <iostream>
#include "cAire.hpp"
#include "cFantassin.hpp"
#include "cArcher.hpp"
#include "cJoueur.hpp"
using namespace std;

int main()
{
    std::cout << "Hello world!" << endl;
    Aire *a=new Aire();

    Joueur o("Oumou",0, a);
    Joueur c("Chloe",11, a);
    //c.setTour();

    Fantassin f;
    Archer archer, archer2;
    Fantassin f2;
    c.creeUnite(&f);
    std::cout<<"1"<<std::endl;
    //c.phase2();
     o.creeUnite(&archer);
    //std::cout<<"2"<<std::endl;
    o.phase2();
    o.creeUnite(&f2);

   //o.creeUnite(&archer);
   o.phase2();
  //  o.avancer(&archer);

    //while(f.getPosition()!=2){
           // c.avancer(&f);
    //}
    //c.attaquer();
    //c.avancer(&f2);
    //c.creeUnite(&archer2);
 std::cout<<"taille av delete " <<o.getUnites().size()<<std::endl;

    //o.miseAJour();
    std::cout<<"taille ap delete " <<o.getUnites().size()<<std::endl;

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
