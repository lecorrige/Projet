#include "Obstacles.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include <iostream>
#include <cmath>
using namespace std;


Obstacle::Obstacle(Vecteur pos)
:pos(pos)
{}

double Obstacle::distance(const ObjetMobile& obj) const{
	return (obj.pos()-point_plus_proche(obj)).norme()-obj.get_rayon();
}
	
ostream& operator<<(ostream& sortie, Obstacle const& obs) {
	return obs.affiche(sortie);
}

void Obstacle::agit_sur(ObjetMobile& obj) const{
	Vecteur n(~(pos-obj.pos()));
	double lambda(1+alpha);
	
	if (distance(obj)<=obj.get_rayon()){
		double F1(obj.get_F()*n);
		obj.ajoute_force(abs(F1)*n);
		
		double v_star((-obj.vit())*n);
		Vecteur vc(obj.vit()+v_star*n);
		Vecteur delta_v;
		
		if ((7*nu*(1+alpha)*v_star)>=2*vc.norme()){
			delta_v=lambda*v_star*n-2/7*vc;
		}
		else {
			delta_v=lambda*v_star*(n-nu*(~vc));
		}
		
		obj.ajoute_vit(delta_v);
	}
}
