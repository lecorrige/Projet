#include "IntegrateurEulerCromer.h"

using namespace std;

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

ostream& IntegrateurEulerCromer::affiche_nom(ostream& sortie) const { 
	sortie<<"Integrateur Euler-Cromer"<<endl;
	return sortie; 
}
