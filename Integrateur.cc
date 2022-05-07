#include <iostream>
#include "Integrateur.h"
#include "ObjetMobile.h"
#include "balle.h"
using namespace std;


Integrateur::Integrateur (double dt) 
: dt(dt)
{}

IntegrateurEulerCromer::IntegrateurEulerCromer (double dt) 
: Integrateur(dt)
{}


void IntegrateurEulerCromer::evolue(ObjetMobile& obj) const { 
   obj.set_vit(obj.get_dP() + dt*obj.evolution());                     
   obj.set_pos(obj.get_P() + dt*obj.get_dP()); 
}

IntegrateurEulerCromer* IntegrateurEulerCromer::copie() const {
	return new IntegrateurEulerCromer(*this);
}

ostream& operator<<(ostream& sortie, Integrateur const& integ) {
	integ.affiche_nom(sortie);
	sortie<<"dt = "
		  <<integ.get_dt()
		  <<endl;
	return sortie;
}

ostream& IntegrateurEulerCromer::affiche_nom(ostream& sortie) const { 
	sortie<<"Integrateur Euler-Cromer"<<endl;
	return sortie; 
}
