#include <iostream>
#include "cAire.hpp"
#include "cBase.hpp"
#include "cFantassin.hpp"
#include "cArcher.hpp"
#include "cJoueur.hpp"



void nouvellePartie(){


    Aire *a=new Aire(12);
    int rep;
    std::string reponse="";
    Joueur * j1;
    Joueur * j2;
    std::cout<<"\t/***************************************BIENVENU(E) DANS AGE OF WAR***************************************/\n\tChoississez un mode de jeu : 1) Humain vs. Humain 2)Humain vs. IA : ";
    std::cin>>rep;
    if(rep==1){
        std::cout<<"\tRentrez le nom du premier joueur : ";
        //std::cin.clear();
        std::cin>>reponse;
        j1=new Joueur(reponse,0, a);
        std::cout<<"\tRentrez le nom du second joueur : ";
        //std::cin.clear();
        std::cin>>reponse;
        j2=new Joueur(reponse,a->getSesCases().size()-1, a);
    }else/* if(rep==2)*/{
        std::cout<<"\tRentrez le nom du joueur : ";
        //std::cin.clear();
        std::cin>>reponse;
        j1=new Joueur(reponse,0, a);
        j2=new Joueur("IA",a->getSesCases().size()-1, a);
    }
    //affichage(j1,j2,a);
    int cpt=0, n=1000;
    bool tourJoueur1=true, q=false;
    while(cpt<n && !j1->estGagnant() && !j2->estGagnant() && !q){

            //std::cout>>"
            if(tourJoueur1){
                q=j1->tour(j2);
                tourJoueur1=false;
                //continue;
            }else{
                q=j2->tour(j1);
                tourJoueur1=true;
            }


        cpt++;
    }
    system("cls");
    if(q){
        std::cout<<"\tVous avez quittez le jeu en cours.\n";
    }
    else if(cpt!=n){
        std::cout<<"\t"<<((j1->estGagnant())?j1->getNom():j2->getNom())<<" a gagne la partie !!!!!!\n";

    }else {
        std::cout<<"\tLa partie s est terminee avant que l un des deux joueurs ne gagnent. Dommage !\n";

    }

    delete a;
    delete j1;
    delete j2;

}



int main()
{
    /*std::cout << "Hello world!" << endl;
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
    // o.creeUnite(&archer);
    //std::cout<<"2"<<std::endl;
    //o.phase2();
    o.creeUnite(&f2);

   //o.creeUnite(&archer);
   //o.phase2();
   o.avancer(&f2);

    while(f.getPosition()!=2){
           c.avancer(&f);
    }
    c.attaquer();
    //c.avancer(&f2);
    //c.creeUnite(&archer2);
 std::cout<<"taille av delete " <<o.getUnites().size()<<std::endl;

    o.miseAJour();
    std::cout<<"taille ap delete " <<o.getUnites().size()<<std::endl;

    c.setTour();
    c.creeUnite(&archer);
    o.setTour();
    o.avancer(&f);
    c.setTour();
    c.avancer(&archer);*/
    /*a->afficheJeu();
    delete(a);*/
    std::string recommencer;
    do{
        nouvellePartie();
        std::cout<<"\tSouhaitez vous recommencer ? o: oui sinon nimporte quelle touche ";
        std::cin>>recommencer;
        system("cls");

    }while(recommencer=="o");


    return 0;
}

