#include "cJoueur.hpp"
#include "cFantassin.hpp"
#include "cCatapulte.hpp"
#include "cArcher.hpp"
#include <stdlib.h>

void Joueur::setTour()
{
    m_tour=true;
    m_sesPieces+=8;
}

bool Joueur::estTour()
{
    return m_tour;
}

void Joueur::creeUnite(Unite* u)
{
    if(!aire->getCase(m_saBase)->estOccupee() && m_sesPieces>u->getPrix())
    {
        m_sesPieces-=u->getPrix();
        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);
        u->setBase(m_saBase);
    }
    else
    {
        std::cout<<"Base deja occupe!!"<<std::endl;
    }
}

void Joueur::creeUnite(/*Unite* u*/)  //Pour le mode IA
{
    Unite * u=NULL;
    if(!aire->getCase(m_saBase)->estOccupee())
    {
        if(m_sesPieces<10)
        {
            return; //on ne peut rien creer
        }
        if(m_sesPieces<12)
        {
            u=new Fantassin;
        }
        else if(m_sesPieces<20)
        {
            u=new Archer;
        }
        else
        {
            u=new Catapulte;
        }
        m_sesPieces-=u->getPrix();

        m_sesUnites.push_back(u);
        aire->getCase(m_saBase)->setUnite(u);
        u->setBase(m_saBase);
    }
}

void Joueur::setBase(int c)
{
    m_saBase=c;
}

int Joueur::getBase()
{
    return m_saBase;
}

void Joueur::avancer(Unite* u)
{
    aire->avancer(u, pas);
}

void Joueur::phase2()
{
    for(size_t i=0; i<m_sesUnites.size(); i++)
    {
        Unite * uniteActu= m_sesUnites[i];
        if(uniteActu->getType()!="Catapulte")
        {
            aire->avancer(uniteActu, pas);
        }
        else
        {
            std::cout<<"CATAPULTE"<<std::endl;
        }
    }


}

void Joueur::phase3()
{
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
}

void Joueur::initPhase()
{
    for(Unite* u:m_sesUnites)
    {
        u->setAttaque(false);
    }
}

void Joueur::phase1()
{
    for(int i=m_sesUnites.size(); i >0 ; i--)
    {
        Unite* uniteActu=m_sesUnites[i-1];
        int n=1;
        bool succes=false;
        while( n <= (uniteActu->getNbEssais()) && !succes)
        {
            std::string typeUnite=uniteActu->getType();
            if(typeUnite=="Catapulte")
            {
                succes=tentativeAtt(uniteActu, n+1);
            }
            else
            {
                succes=tentativeAtt(uniteActu, n);
            }
            n+=1;
        }
    }
}

bool Joueur::tentativeAtt(Unite* u, int n)
{
    if(aire->getCase(u->getPosition()+pas*n)->estOccupee() && aire->getCase(u->getPosition()+pas*n)->getUnite()->getBase()!=m_saBase)
    {
       Unite* ptr_ennemi=aire->getCase(u->getPosition()+pas*n)->getUnite();
        //Il ne s'attaque pas lui meme
        ptr_ennemi->setPtV(ptr_ennemi->getPtV()-2*u->getPtAt());

        if(ptr_ennemi->getPtV()<=0)
        {
            aire->getCase(ptr_ennemi->getPosition())->deleteUnite();
            m_sesPieces+=(ptr_ennemi->getPrix()/2);
            if(u->getType() == "Fantassin" && ptr_ennemi->getType()=="Fantassin")
            {
                u->setType("Super-soldat");
            }
            //delete ptr_ennemi;
        }

        if(u->getType()=="Catapulte")
        {
            int autreCase;
            if(n<3)
            {
                autreCase=(n+1);
            }
            else
            {
                autreCase=n-1;
            }
            if(aire->getCase(u->getPosition()+pas*n)->estOccupee())
            {
                Unite* ptr_ennemi2=aire->getCase(u->getPosition()+pas*autreCase)->getUnite();
                ptr_ennemi2->setPtV(ptr_ennemi2->getPtV()-2*u->getPtAt());

                if(ptr_ennemi2->getPtV()<=0)
                {
                    aire->getCase(ptr_ennemi2->getPosition())->deleteUnite();
                    m_sesPieces+=(ptr_ennemi->getPrix()/2);
                    //delete ptr_ennemi;
                }
            }
        }
        u->setAttaque(true);
        return true;
    }
    else if(((u->getPosition()+pas*n)== m_saBase+11*pas) && !(aire->getCase(u->getPosition()+pas*n)->estOccupee()))
    {
        std::cout<<"je veux attaquer ta base"<<std::endl;
        Base* bAdverse=(Base*) aire->getCase(u->getPosition()+pas*n);
        bAdverse->setPtV(bAdverse->getPtV()-2*u->getPtAt());
        std::cout<<"point de vie restant de la base "<< bAdverse->getPtV() <<std::endl;
        u->setAttaque(true);
        return true;
    }
    //personne sur la case donc pas attaquer
    u->setAttaque(false); //pas forcement utile
    return false;
}

void Joueur::miseAJour()
{
    for(size_t i=0; i<m_sesUnites.size(); i++)
    {
        if(m_sesUnites[i]->getPtV()<=0)
        {
            m_sesUnites.erase(m_sesUnites.begin()+i);
        }
    }
}

std::vector<Unite*> Joueur::getUnites()
{
    return m_sesUnites;
}

void Joueur::tour()
{
    phase1();
    phase2();
    phase3();
}
