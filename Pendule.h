#pragma once

#include "ObjetMobile.h"
#include "Vecteur.h"

class Pendule : public ObjetMobile
{
private:
	double L;
	double frottement;
	Vecteur d;
	Vecteur pos_bout;

public:
	Vecteur evolution() const; 
	
	Pendule (double R, double m_vol, Vecteur P, Vecteur dP, Vecteur pos, Vecteur vit, Vecteur F,
			 double L, double frott, Vecteur d, Vecteur pos_bout);
	
	std::ostream& affiche(std::ostream& sortie,  Pendule const& p);
	
	double get_L() const { return L; }
	
	double get_fr() const { return frottement; }
	
	Vecteur get_d() const { return d; }
	
	Vecteur get_pos_bout() const { return pos_bout; }
};

std::ostream& operator<<(std::ostream& sortie,  Pendule const& p);
