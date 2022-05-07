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

void Obstacle::agit_sur(ObjetMobile& obj, bool afficher) {
	Vecteur n(normale(obj));
	double lambda(1+alpha);
	
	if (distance(obj)<=obj.get_rayon()){
		double F1(obj.get_F()*n);
		if (F1<0) {obj.ajoute_force(-F1*n);}
		
		double v_star(-(obj.vit()*n));
		double coeff(7*nu*lambda*v_star);
		Vecteur vc(obj.vit()+v_star*n);
		Vecteur delta_v;
		
		if (coeff>=2*vc.norme()){
			delta_v=lambda*v_star*n-(2/7)*vc;
		}
		else {
			delta_v=lambda*v_star*(n-nu*(~vc));
		}
		
		if (afficher) {
			cout << "calculs :" << endl;
			cout << "  n = " << n << endl;
			cout << "  vstar = " << v_star << endl;
			cout << "  vc = " << vc << endl;
			cout << "  7 mu (1+alpha) vstar = " << coeff << endl;
			cout << "  dv = " << delta_v << endl;
		}
		
		obj.ajoute_vit(delta_v);
	}
}

void Obstacle::test_choc(ObjetMobile& obj) {
	cout << "avant choc : " << endl;
	cout << "      vitesse = " << obj.vit() << endl;
	cout << "      force = " << obj.get_F() << endl << endl;
	agit_sur(obj, true);
	cout << endl << "après choc : " << endl;
	cout << "      vitesse = " << obj.vit() << endl;
	cout << "      force = " << obj.get_F() << endl << endl;
}
	
	
