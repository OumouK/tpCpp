#include "cJoueur.hpp"
#include "cFantassin.hpp"
#include "cCatapulte.hpp"
#include "cArcher.hpp"
#include <stdlib.h>
#include <iostream>

void Joueur::setGagnant(){
    m_victoire=true;
}

bool Joueur::estGagnant(){
    return m_victoire;
}

std::string Joueur::getNom(){
    return m_nom;
}

//int Joueur::getPieces(){
  //  return m_sesPieces;
//}

//creation d'une unite u passee en parametre pour un joueur: renvoie true si l unite a ete creer, false sinon
bool Joueur::creeUnite(Unite* u){
    //on verifie d abord si la base n est pas occupee et que le joueur a les moyens de creer l unite
    if(!aire->getCase(m_saBase)->estOccupee() && m_sesPieces>=u->getPrix()){
        std::cout<<"\tUne unite de type "<<u->getType()<<" va etre creee sur la base de " <<m_nom<<".\n";
        m_sesPieces-=u->getPrix();
        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);
        u->setBase(m_saBase);
        return true;

    }else{
        std::cout<<"\tL'unite n a pas pu etre creee car vous n'avez pas les fonds necessaires. Il vous reste :\n"<<m_sesPieces<<" pieces.\n";
        return false;
    }
}

void Joueur::creeUnite(){ //Pour le mode IA
    Unite * u=NULL;
    if(m_sesPieces<10){
        std::cout<<"\tIA n'a pu cree aucune unite car il n a pas assez de pieces.\n";
        return; //on ne peut rien creer
    }
    if(m_sesPieces<12){
        u=new Fantassin;
    }
    else if(m_sesPieces<20){
        u=new Archer;
    }
    else {
        u=new Catapulte;
    }
    creeUnite(u);
}

int Joueur::getBase(){
    return m_saBase;
}


void Joueur::phase2(){
std::cout<<"\t/***********************************************PHASE 2***********************************************/"<<std::endl;

for(size_t i=0; i<m_sesUnites.size(); i++)
    {
        Unite * uniteActu= m_sesUnites[i];
        if(uniteActu->getType()!="Catapulte")
        {
            aire->avancer(uniteActu, pas);
        }
        else
        {
            std::cout<<"\tLa catapulte situee case "<<uniteActu->getPosition()<<" n a pas pu avancer car nous sommes en phase 2."<<std::endl;
        }
    }


}

void Joueur::phase3(){
    std::cout<<"\t/***********************************************PHASE 3***********************************************/"<<std::endl;

     for(size_t i=0; i<m_sesUnites.size(); i++)
    {
        Unite * uniteActu= m_sesUnites[i];

        if(uniteActu->getType()=="Catapulte" && !uniteActu->getAttaque())
        {
            aire->avancer(uniteActu, pas);
        }
        else if(uniteActu->getType()=="Fantassin" && !uniteActu->getAttaque())   //Fantassin qui n'a pas pu attaquer
        {
            tentativeAtt(uniteActu, 1);
        }
        else if(uniteActu->getType()=="Super-soldat")   //Super soldat qui n'a pas pu attaquer
        {
            tentativeAtt(uniteActu, 1);
        }
    }
    initPhase();
}

//pour reinitialiser les attaques des unites a la fin d un tour
void Joueur::initPhase(){
    for(Unite* u:m_sesUnites){
        u->setAttaque(false);
    }
}

void Joueur::phase1(){
    //l'unite la plus proche de la base du joueur courant attaque
    std::cout<<"\t/***********************************************PHASE 1***********************************************/"<<std::endl;
     if(m_sesUnites.size()==0){
        std::cout<<"\t"<<m_nom<<" ne possede pas d unite pour attaquer.\n";
     }else{

         for(int i=m_sesUnites.size(); i >0 ; i--)
    {
        Unite* uniteActu=m_sesUnites[i-1];
        int n=1;
        //bool succes=false;
        while( n <=uniteActu->getNbEssais() && !uniteActu->getAttaque())
        {
            std::string typeUnite=uniteActu->getType();
            if(typeUnite=="Catapulte")
            {
                tentativeAtt(uniteActu, n+1);
            }
            else
            {
                tentativeAtt(uniteActu, n);
            }
            n+=1;
        }
        if(!uniteActu->getAttaque()){
            std::cout<<"\tL'unite a la case "<<uniteActu->getPosition()<<" n a pu attaquer personne.\n";
        }
    }}

    }

void Joueur::tentativeAtt(Unite* u, int n){
    //Il tente d attaquer une case occupee par une unite ennemie
    if(aire->getCase(u->getPosition()+pas*n)->estOccupee() && aire->getCase(u->getPosition()+pas*n)->getUnite()->getBase()!=m_saBase){
            Unite* ptr_ennemi=aire->getCase(u->getPosition()+pas*n)->getUnite();
            ptr_ennemi->setPtV(ptr_ennemi->getPtV()-u->getPtAt());
            std::cout<<"\t"<<m_nom<<" a attaque un"<<((ptr_ennemi->getType()=="Catapulte")? "e ennemie":" ennemi")<<" situe a la case "<< ptr_ennemi->getPosition()<<" avec son unite de type "<<u->getType()<<" situe a la case "<<u->getPosition()<<".\n";
            if(ptr_ennemi->getPtV()<=0){
                // Le joueur dont l’unite a remporte le combat reçoit de l’or suppl équivalent à la moitie du prix de l’unite defaite
                m_sesPieces+=(ptr_ennemi->getPrix()/2);
                std::cout<<"\tL ennemi a ete neutralise avec succes.\n";
                if(u->getType()=="Fantassin" && ptr_ennemi->getType()=="Fantassin" ){
                    u->setType("Super-soldat");
                }
                aire->getCase(ptr_ennemi->getPosition())->deleteUnite();

                //delete ptr_ennemi;
            }

            if(u->getType()=="Catapulte"){

                    int autreCase;
                    if(n<=3){
                        //quand il s agit des deux premieres tentatives
                        autreCase=(n+1);

                    }else{
                        //quand il s agit de la derniere tentative
                        autreCase=n-1;

                    }
                    if(aire->getCase(u->getPosition()+pas*autreCase)->estOccupee()){

                        Unite* ptr_ennemi2=aire->getCase(u->getPosition()+pas*autreCase)->getUnite();
                        ptr_ennemi2->setPtV(ptr_ennemi2->getPtV()-u->getPtAt());
                        std::cout<<"\t"<<m_nom<<" a egalement attaque une unite situee a la case "<< ptr_ennemi2->getPosition()<<std::endl;


                        if(ptr_ennemi2->getPtV()<=0){

                            aire->getCase(ptr_ennemi2->getPosition())->deleteUnite();
                        }


                    }

            }
        u->setAttaque(true);

    }
    //Si une unite peut attaquer la base ennemie
    else if(((u->getPosition()+pas*n)== m_saBase+11*pas) && !(aire->getCase(u->getPosition()+pas*n)->estOccupee()))
    {
        std::cout<<"\t"<<m_nom<<" attaque la base ennemie."<<std::endl;
        Base* bAdverse=(Base*) aire->getCase(u->getPosition()+pas*n);
        bAdverse->setPtV(bAdverse->getPtV()-u->getPtAt());
        if(bAdverse->getPtV()>0){
            std::cout<<"\tIl reste "<< bAdverse->getPtV()<<" points a la base ennemie."<<std::endl;
        }else{
            //L ennemi est vaincu
            m_victoire=true;
            return;
        }

        u->setAttaque(true);
    }/*else{

        u->setAttaque(false);
    }*/

}

//dans le cas ou le joueur a perdu des unites, mortes au combat
void Joueur::miseAJour(){

    for(size_t i=0;i<m_sesUnites.size();i++){
         if(m_sesUnites[i]->getPtV()<=0){
            m_sesUnites.erase(m_sesUnites.begin()+i);
        }
    }
}

bool Joueur::tour(Joueur * ennemi){

    system("cls"); //ligne pour effacer ce qu'il y a d ecrit sur la console
    aire->afficheJeu(); //affiche l aire de jeu
    affiche(ennemi); //affiche les deux joueur dans le bon ordre: d abord base 0 puis base 11
    m_sesPieces+=8;
    std::cout << "\t"<<m_nom<< " , vous avez survecu un tour. Vous remportez donc 8 pieces.Vous avez desormais "<<m_sesPieces<<" pieces.\n";
    std::string rep;
    bool q=false;
    phase1();
    miseAJour(); //on met a jour les unites du joueur actuel dans le cas ou sa catapulte a tue une de ses unites
    ennemi->miseAJour();
    phase2();
    phase3();
    ennemi->miseAJour();
    if(m_nom!="IA" && !aire->getCase(m_saBase)->estOccupee()){
        q=demandeCreationUnite();
        if(q){
            system("cls");
            std::cout<<"\tVous avez quitte le jeu en cours.\n";
            return true;
        }
    }else{
        creeUnite();
    }
    while(rep==""){
            if(m_nom=="IA"){
                std::cout << "\t"<<ennemi->getNom()<<" ,IA a fini de jouer";
            }else{
                std::cout << "\t"<<m_nom<< " ,fin du tour";
            }
        std::cout<<". Pour continuer, appuyez sur nimporte quelle autre touche (q:quitter) ";
        std::cin>>rep;
        if(rep=="q"){
            system("cls");
            std::cout<<"\tVous avez quitte le jeu en cours.\n";
            return true;
        }
    }

    return false;

}

bool Joueur::demandeCreationUnite(){
    bool retry=false;
    bool q=false;
    do{
    std::string rep="";

    std::cout << "\t"<<m_nom<< " ,souhaitez vous creer une nouvelle unite ? \tChoisissez: f: fantassin(10 pieces), a:archer(12 pieces), c:catapulte (20 pieces), n:si vous ne souhaitez pas creer d'unite : (q:quitter)";
        std::cin>>rep;

        if(rep=="f"){
            retry=creeUnite(new Fantassin());

        }

        else if(rep=="a"){
           retry=creeUnite(new Archer());
        }

        else if(rep=="c"){
            retry=creeUnite(new Catapulte());
        }
         else if(rep=="n"){
            retry=true;
         }

        else if(rep=="q"){
            q=true;
        }else{
            std::cout<<"\tCaractere non reconnu. Veuillez recommencer.\n";
        }

    } while(!retry && !q);
return q;
}




std::vector<Unite*> Joueur::getUnites(){
    return m_sesUnites;
}

void Joueur::affiche(){
    std::cout<<"\tPieces restantes : "<<m_sesPieces<<std::endl;
    std::cout<<"\tPoints de vie restants : "<<((Base*)aire->getCase(m_saBase))->getPtV()<<std::endl;
    for(Unite* u:m_sesUnites){
       u->affiche();
    }
}

void Joueur::affiche(Joueur * ennemi){
    Joueur *a;
    Joueur *b;
    if(m_saBase==0){
        a=this;
        b=ennemi;

    }
    else{
        a=ennemi;
        b=this;
    }
    std::cout<<"\n\n";
    std::cout<<"\t"<<a->getNom()<<": o"<<std::endl;
    a->affiche();
    std::cout<<std::endl;
    std::cout<<"\t"<<b->getNom()<<": x"<<std::endl;
    b->affiche();
    std::cout<<std::endl;
}
