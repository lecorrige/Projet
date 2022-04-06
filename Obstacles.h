#pragma once

#include "Vecteur.h"
#include "ObjetMobile.h"

class Obstacle {
protected:
	Vecteur pos;

public:
	 Obstacle (Vecteur pos=(3));
	 
	 double distance(const ObjetMobile&) const;
	 void agit_sur(ObjetMobile&) const;
	 
	 virtual Vecteur point_plus_proche(const ObjetMobile&) const =0;
	 virtual std::ostream& affiche(std::ostream&) const =0;
};

std::ostream& operator<<(std::ostream&, Obstacle const&);
