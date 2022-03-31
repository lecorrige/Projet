#pragma once

#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"

class Balle : public ObjetMobile {
public:
	using ObjetMobile::ObjetMobile;     //attention si nouveaux attributs
	
	Vecteur evolution() const;
	
	Vecteur get_pos() const { return P; }  
	Vecteur get_vit() const { return dP; }
	/*void set_pos(Vecteur const& p) { P=p; }
	void set_vit(Vecteur const& v) { dP=v; }*/   // pas utile
	virtual Vecteur pos() const override { return get_pos(); }
	virtual ostream& affiche(ostream& sortie) const override;
};


