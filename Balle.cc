#include <iostream>
#include "balle.h"
#include "ObjetMobile.h"
#include "constantes.h"
using namespace std;


Vecteur Balle::evolution() const {
	test_masse();         //on teste si masse pas valable
	return F/masse();
}


ostream& Balle::affiche(ostream& sortie) const {
	sortie << "une balle" << endl;
	ObjetMobile::affiche(sortie);
	sortie << get_pos() << " # position balle" << endl;
	sortie << get_vit() << " # vitesse balle" << endl;
	sortie << get_force() << " # force balle" << endl;
	sortie << evolution() << " # f()" << endl;
	return sortie;
}

