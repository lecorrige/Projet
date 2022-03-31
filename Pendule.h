#pragma once

#include "ObjetMobile.h"
#include "Vecteur.h"

class Pendule : public ObjetMobile
{
private:
	const double L;    //longueur du pendule
	const Vecteur O;   //origine du pendule
	Vecteur d;         //direction du pendule

public:
    Pendule (double R, double m_vol, double L, double b, Vecteur P, Vecteur dP, 
             Vecteur d, Vecteur O=(3));
    Pendule (double R=0, double m_vol=0, double L=0, double b=0, int deg=1); 

	Vecteur evolution() const; 
	double get_L() const { return L; }
	Vecteur get_O() const {return O;}
	Vecteur get_d() const {return d;}
	Vecteur pos_masse() const;    //calcule la position du bout du pendule
	Vecteur vit_masse() const;    //calcule la vitesse du bout du pendule
	
	virtual Vecteur pos() const override {return pos_masse();}  
	virtual ostream& affiche(ostream& sortie) const override;
};

