#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "balle.h"
using namespace std;


double Balle::masse_volumique() {
	return (3/(4*M_PI*rayon*rayon*rayon));
}

void Balle::ajoute_force(Vecteur const& df) {
	force += df;
}
