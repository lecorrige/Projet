#include <iostream>
#include "balle.h"
#include "ObjetMobile.h"
#include "constantes.h"
using namespace std;


ostream& operator<<(ostream& sortie, Balle const& balle) {
	const ObjetMobile& o(balle);
	cout << "une balle : " << endl;
	sortie << o;
	sortie << balle.get_P() << " # parametre" << endl;
	sortie << balle.get_dP() << " # vitesse" << endl;
	sortie << balle.evolution() << " # f()" << endl;
	return sortie;
}

Vecteur Balle::evolution() const {
	test_masse();         //on teste si masse pas valable
	return F*(1/masse());
}
