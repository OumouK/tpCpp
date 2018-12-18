#ifndef CJoueur_H_INCLUDED
#define CJoueur_H_INCLUDED

#include"cUnite.hpp"

class Joueur {
	protected:
	int m_pieceOr;
	bool monTour;
	Base b;
	std::vector<Unite> sesunités;
	
	public:
		Joueur(int piece): m_pieceOr(piece){};
    		int getPieceOr(){return m_pieceOr;}
};

#endif
