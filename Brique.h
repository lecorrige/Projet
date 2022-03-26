#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Obstacle.h"
#include <vector>

class Brique : public Obstacle
{
private:
	Vecteur L;
	Vecteur l;
	double h;

public:
	Brique (Vecteur pos, Vecteur longueur, Vecteur largeur, double h);
	
	Vecteur proche_plan_fini(const ObjetMobile& obj, Vecteur pos, double L, Vecteur eL, double l, Vecteur el) const;
	
	Vecteur point_plus_proche(const ObjetMobile& obj) const;
	
	Vecteur min(std::vector<Vecteur> x);
};
