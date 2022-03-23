#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "balle.h"
#include "ChampForces.h"
using namespace std


void ChampForces::agit_sur(Balle balle){
	double force;
	double const rho(1.2);
	force = (balle.m - 4*M_PI*pow(balle.r, 3)*rho/3)*intensite;
	balle.ajoute_force(force);
}
	
