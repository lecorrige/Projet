#include <iostream>
#include "Integrateur.h"
#include "ObjetMobile.h"
using namespace std;


Integrateur::Integrateur (double dt) 
: dt(dt)
{}


ostream& operator<<(ostream& sortie, Integrateur const& integ) {
	integ.affiche_nom(sortie);
	sortie<<"dt = "
		  <<integ.get_dt()
		  <<endl;
	return sortie;
}

