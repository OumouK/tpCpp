#include "cJoueur.hpp"
#include "cFantassin.hpp"
#include "cCatapulte.hpp"
#include "cArcher.hpp"
#include <stdlib.h>
#include <iostream>

void Joueur::setGagnant(){
    m_victoire=true;
    //m_sesPieces+=8;
}

bool Joueur::estGagnant(){
    return m_victoire;
}

std::string Joueur::getNom(){
    return m_nom;
}

int Joueur::getPieces(){
    return m_sesPieces;
}

void Joueur::creeUnite(Unite* u){

    if(!aire->getCase(m_saBase)->estOccupee() && m_sesPieces>=u->getPrix()){
        std::cout<<"\tUne unite de type "<<u->getType()<<" va etre creee sur la base de " <<m_nom<<".\n";
        m_sesPieces-=u->getPrix();

        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);
        u->setBase(m_saBase);

    }else{
        std::cout<<"\tL'unite n a pas pu etre creee car la base est occupee ou bien vous n avez pas les fonds necessaires.\n"<<m_sesPieces<<"\n";
    }
}

void Joueur::creeUnite(){ //Pour le mode IA
    Unite * u=NULL;
    //if(!aire->getCase(m_saBase)->estOccupee()){
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
       /* m_sesPieces-=u->getPrix();
        std::cout<<"\tUne unite de type "<<u->getType()<<" va etre creee sur la base de " <<m_nom<<".\n";
        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);
        u->setBase(m_saBase);*/
        creeUnite(u);
    //}



}

int Joueur::getBase(){
    return m_saBase;
}


void Joueur::phase2(){
   /* size_t cpt=0;
    while(cpt<m_sesUnites.size()){ //toutes les nités nont pas attaquer
        Unite * uniteLoin=NULL;
        int distMin=-1;
        for(Unite * u:m_sesUnites){
        int distActu=std::abs(u->getPosition()-m_saBase);
        if(distActu>distMin && !u->getAttaque()){
           distMin=distActu;
           uniteLoin=u;

        }
        }
        uniteLoin->setAttaque(true);
       if(uniteLoin->getType()!="Catapulte"){
            aire->avancer(uniteLoin, pas);
            std::cout<<"AVAAANCE"<<uniteLoin->getPosition()<<std::endl;

       }else{
        std::cout<<"CATAPULTE"<<std::endl;
       }



        cpt++;
        }
        initPhase();

       // ordonne();
*/
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
            /*succes=*/tentativeAtt(uniteActu, 1);
        }
        else if(uniteActu->getType()=="Super-soldat")   //Fantassin qui n'a pas pu attaquer
        {
            /* succes=*/tentativeAtt(uniteActu, 1);
        }
    }
    initPhase();
}

void Joueur::initPhase(){
    for(Unite* u:m_sesUnites){
        u->setAttaque(false);
    }
}

/*void Joueur::ordonneProche(){
    size_t cpt=0;
    while(m_sesUnites.size()!=0){ //toutes les nités nont pas attaquer
    Unite * uniteProche=NULL;
    int distMax=15;
    for(int i=0;i<m_sesUnites.size();i++){
        int distActu=std::abs(u->getPosition()-m_saBase);
        if(distActu <distMax){
            distMax=distActu;
            //u->setAttaque(true);
            uniteProche=u;


        }
    }
}
}*/

void Joueur::phase1(){
    //l'unite la plus proche de la base du joueur courant attaque

    /*size_t cpt=0;
    while(cpt<m_sesUnites.size()){ //toutes les nités nont pas attaquer
    Unite * uniteProche=NULL;
    int distMax=15;
    for(Unite * u:m_sesUnites){
        int distActu=std::abs(u->getPosition()-m_saBase);
        if(distActu <distMax && !u->getAttaque()){
            distMax=distActu;
            //u->setAttaque(true);
            uniteProche=u;

        }
    }
    uniteProche->setAttaque(true);
    //uniteProche->attaquer(aire, pas);
std::cout<<"test j'attaque "<<uniteProche->getPosition()<<std::endl;
 //pour dire s'il a tenter d'attaquer
int n=1;
bool succes=false;
while(n<=uniteProche->getNbEssais() && !succes){
  std::string typeUnite=uniteProche->getType();
  if(typeUnite!="Catapulte"){
    succes=tentativeAtt(uniteProche, n);
  }
  n+=1;

}

        cpt++;
    }*/
//if(m_saBase==0){
    std::cout<<"\t/***********************************************PHASE 1***********************************************/"<<std::endl;
     if(m_sesUnites.size()==0){
        std::cout<<"\t"<<m_nom<<" ne possede pas d unite.\n";
     }else{

         for(int i=m_sesUnites.size(); i >0 ; i--)
    {
        Unite* uniteActu=m_sesUnites[i-1];
        int n=1;
        //bool succes=false;
        while( n <=uniteActu->getNbEssais() && !uniteActu->getAttaque())
        {
             std::cout<<"\tHEEEEEEERE.\n"<<n<<" "<<uniteActu->getNbEssais();
            std::string typeUnite=uniteActu->getType();
            if(typeUnite=="Catapulte")
            {
                /*succes=*/tentativeAtt(uniteActu, n+1);
            }
            else
            {
                /*succes=*/tentativeAtt(uniteActu, n);
            }
            n+=1;
        }
    }}

    }

void Joueur::tentativeAtt(Unite* u, int n){

if(aire->getCase(u->getPosition()+pas*n)->estOccupee() && aire->getCase(u->getPosition()+pas*n)->getUnite()->getBase()!=m_saBase){
            //std::cout<<"j'attaque "<<u->getPosition()<<std::endl;
            Unite* ptr_ennemi=aire->getCase(u->getPosition()+pas*n)->getUnite();
            //Il ne s'attaque pas lui meme

            ptr_ennemi->setPtV(ptr_ennemi->getPtV()-u->getPtAt());

             std::cout<<"\t"<<m_nom<<" a attaque un"<<((ptr_ennemi->getType()=="Catapulte")? "e ennemie":" ennemi")<<" situe a la case "<< ptr_ennemi->getPosition()<<std::endl;
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
                    if(n<3){

                            autreCase=(n+1);

                    }else{
                          autreCase=n-1;

                    }
                    if(aire->getCase(u->getPosition()+pas*autreCase)->estOccupee()){

                       Unite* ptr_ennemi2=aire->getCase(u->getPosition()+pas*autreCase)->getUnite();
                 ptr_ennemi2->setPtV(ptr_ennemi2->getPtV()-u->getPtAt());
                 std::cout<<"\t"<<m_nom<<" a egalement attaque une unite "<<((ptr_ennemi2->getType()=="Catapulte")? "e ennemie":" ennemi")<<" situe a la case"<< ptr_ennemi2->getPosition()<<std::endl;


            if(ptr_ennemi2->getPtV()<=0){

                aire->getCase(ptr_ennemi2->getPosition())->deleteUnite();

                //delete ptr_ennemi;
            }


            }

                       }
    u->setAttaque(true);
            //return true;
        }
         else if(((u->getPosition()+pas*n)== m_saBase+11*pas) && !(aire->getCase(u->getPosition()+pas*n)->estOccupee()))
    {
        std::cout<<"\t"<<m_nom<<" attaque la base ennemie."<<std::endl;
        Base* bAdverse=(Base*) aire->getCase(u->getPosition()+pas*n);
        bAdverse->setPtV(bAdverse->getPtV()-u->getPtAt());
        if(bAdverse->getPtV()>0){
            std::cout<<"\tIl reste "<< bAdverse->getPtV()<<" points a la base ennemie."<<std::endl;
        }else{
            m_victoire=true;

        }

        u->setAttaque(true);
        //return true;
    }else{
     std::cout<<"\tL'unite a la case "<<u->getPosition()<<" n a pu attaquer personne.\n";
        u->setAttaque(false); //pas forcement utile
    }
        //personne sur la case donc pas attaquer

        //return false;
}

void Joueur::miseAJour(){

    for(size_t i=0;i<m_sesUnites.size();i++){
         if(m_sesUnites[i]->getPtV()<=0){
            m_sesUnites.erase(m_sesUnites.begin()+i);
        }
    }
}

void Joueur::tour(Joueur * ennemi){

    system("cls"); //ligne pour effacer ce qu'il y a d ecrit sur la console
    aire->afficheJeu(); //affiche l aire de jeu
    affiche(ennemi); //affiche les deux joueur dans le bon ordre: d abord base 0 puis base 11
    m_sesPieces+=8;
    std::cout << "\t"<<m_nom<< " , vous avez survecu un tour. Vous donc remportez 8 pieces.Vous avez desormais "<<m_sesPieces<<" pieces.\n";
    std::string rep;
    phase1();
    miseAJour();
    ennemi->miseAJour();
    //system("cls");
    //aire->afficheJeu();
    //affiche(ennemi);
    phase2();
    //system("cls");
    //aire->afficheJeu();
    //    affiche(ennemi);
    phase3();
    miseAJour();
    ennemi->miseAJour();
    //system("cls");
    //aire->afficheJeu();
    //affiche(ennemi);
    if(m_nom!="IA"){
        demandeCreationUnite();
    }else{
        creeUnite();
    }
    while(rep==""){
            if(m_nom=="IA"){
                std::cout << "\t"<<ennemi->getNom()<<" ,IA a fini de jouer";
            }else{
                std::cout << "\t"<<m_nom<< " ,fin du tour";
            }
        std::cout<<". Pour continuer, appuyez sur nimporte quelle autre touche ";
        std::cin>>rep;
    }
    //ennemi->miseAJour();


    //creeUnite();

}

void Joueur::demandeCreationUnite(){
    std::string rep="";
    std::cout << "\t"<<m_nom<< " ,souhaitez vous creer une nouvelle unite ? \tChoisissez: f: fantassin(10 pieces), a:archer(12 pieces), c:catapulte (20 pieces) : ";
        std::cin>>rep;
        if(rep=="f"){
            creeUnite(new Fantassin());
        }
        else if(rep=="a"){
            creeUnite(new Archer());
        }
        else if(rep=="c"){
            creeUnite(new Catapulte());
        }else{
            std::cout<<"\tAucune unite ne veut etre cree.\n";
        }

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
