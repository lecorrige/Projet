#pragma once

#include "Vecteur.h"
#include "ObjetMobile.h"

class Obstacle {
protected:
	Vecteur pos;
	
	virtual Vecteur normale(const ObjetMobile&) const =0;
public:
	Obstacle (Vecteur pos=(3));
	 
    double distance(const ObjetMobile&) const;
	void agit_sur(ObjetMobile&, bool=false);
	 
	virtual Vecteur point_plus_proche(const ObjetMobile&) const =0;
	virtual std::ostream& affiche(std::ostream&) const =0;
	virtual Obstacle* copie() const =0;
	void test_choc(ObjetMobile&);
	Vecteur get_O() const {return pos;}
};

std::ostream& operator<<(std::ostream&, Obstacle const&);
