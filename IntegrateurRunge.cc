#include "IntegrateurRunge.h"
#include "Vecteur.h"
#include <cmath>

using namespace std;

IntegrateurRunge::IntegrateurRunge(double dt)
:Integrateur(dt)
{}

void IntegrateurRunge::evolue(ObjetMobile& obj) const { 
	Vecteur dPn1(obj.get_dP());
	Vecteur Pn1(obj.get_P());
	
	Vecteur k1(dPn1);
	Vecteur k1p(obj.evolution());
	
	Vecteur k2(dPn1+dt*k1p/2);
	obj.set_vit(k2); obj.set_pos(Pn1+dt*k1/2);
	Vecteur k2p(obj.evolution());
	
	Vecteur k3(dPn1+dt*k2p/2);
	obj.set_vit(k3); obj.set_pos(Pn1+dt*k2/2);
	Vecteur k3p(obj.evolution());
	
	Vecteur k4(dPn1+dt*k3p);
	obj.set_vit(k3); obj.set_pos(Pn1+dt*k3);
	Vecteur k4p(obj.evolution());
	
	obj.set_pos(Pn1+dt*(k1+2*k2+2*k3+k4)/6);
	obj.set_vit(dPn1+dt*(k1p+2*k2p+2*k3p+k4p)/6);
};

IntegrateurRunge* IntegrateurRunge::copie() const {
	return new IntegrateurRunge(*this);
}

ostream& IntegrateurRunge::affiche_nom(ostream& sortie) const { 
	sortie<<"Integrateur Runge-Kutta"<<endl;
	return sortie; 
}
