#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Obstacles.h"
#include <vector>

class Brique : public Obstacle {
private:
	Vecteur L;     //longueur
	Vecteur l;     //largeur
	double h;      //hauteur
	
	Vecteur min(std::vector<Vecteur> const&, const ObjetMobile&) const;
	Vecteur proche_plan_fini(const ObjetMobile& obj, Vecteur pos, double L, 
	                         Vecteur eL, double l, Vecteur el) const;
	virtual Vecteur normale(const ObjetMobile&) const override;
	Plan face_plus_proche(const ObjetMobile&) const;

public:
	Brique (Vecteur pos=(3), Vecteur longueur=(3), Vecteur largeur=(3), double h=0);
	
	virtual Vecteur point_plus_proche(const ObjetMobile& obj) const override;
	virtual std::ostream& affiche(std::ostream&) const override;
	virtual Brique* copie() const override; 
	Vecteur get_L() const {return L;}
	Vecteur get_l() const {return l;}
};
