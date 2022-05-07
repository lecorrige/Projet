#include "ChampForces.h"
#include "Objet.h"
#include "Vecteur.h"

class Vent : public ChampForces {
public:
	Vent(Vecteur o, Vecteur n, double l, double L,
		 double p, Vecteur v=g, bool po=true);
		 
	bool est_dans(ObjetMobile const& obj) const;
	double get_l() const { return largeur; }
	double get_L() const { return longueur; }
	double get_p() const { return profondeur; }
	Vecteur get_O() const { return origine; }
	Vecteur get_n() const { return normale; }
	void set_l(double x) { largeur=x; }
	void set_L(double x) { longueur=x; }
	void set_O(double x) { origine=x; }
	
private:
	Vecteur origine;
	Vecteur normale;
	double largeur;
	double longueur;
	double profondeur;
};
