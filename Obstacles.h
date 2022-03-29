#include "Vecteur.h"
#include "ObjetMobile.h"

class Obstacle
{
protected:
	Vecteur pos;

public:
	 Obstacle (Vecteur pos);

	 double distance(const ObjetMobile& obj) const;
	 
	 void agit_sur(ObjetMobile obj) const;
	 
	 virtual Vecteur point_plus_proche(const ObjetMobile& obj)=0 const;

};
