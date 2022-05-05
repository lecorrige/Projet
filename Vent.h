#include "ChampForces.h"
#include "Objet.h"
#include "Vecteur.h"

class Vent : public ChampForces {
public:
	Vent(Vecteur o, Vecteur n, double l, double L,
		 double p, Vecteur v=g, bool p=true);
		 
	bool est_dans(Objet const& obj) const;
	double get_l() const { return largeur; }
	double get_L() const { return longueur; }
	Vecteur get_O() const { return origine; }
	Vecteur get_n() const { return normale; }
	void set_l(double x) { l=x; }
	void set_L(double x) { L=x; }
	void set_O(double x) { origine=x; }
	
private:
	Vecteur origine;
	Vecteur normale;
	double largeur;
	double longueur;
	double profondeur;
};
