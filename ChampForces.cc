#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ChampForces.h"
#include "constantes.h"
#include <ostream>
using namespace std;

ChampForces ::ChampForces(Vecteur v, bool test)
: intensite(v), poussee(test)
{}

ostream& operator<<(ostream& sortie, ChampForces const& f) {
	cout << "un champ de force :" << endl;
	sortie << f.get_intensite() << " # intensite" << endl;
	return sortie;
}

void ChampForces::agit_sur(ObjetMobile& obj) const {
	double k;
	Vecteur v(3);
	if (obj.get_F() == v) {obj.set_F(intensite.get_vecteur().size());}
	if (poussee) {k=(obj.masse()-4*M_PI*rho_air*pow(obj.get_rayon(), 3)/3);}
	else {k=obj.masse();}
	obj.ajoute_force(k*intensite);
}
