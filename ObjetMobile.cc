#include <iostream>
#include <string>
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "constantes.h"
#include <cmath>

using namespace std;

double ObjetMobile::masse() const {   //creer fonction inverse en fonction rayon
	return (m_vol*pow(R, 3)*K);
}

void ObjetMobile::agit_sur(ObjetMobile& obj, bool test) {
	Vecteur n(~(pos()-obj.pos()));
	double lambda(((1+alpha)*obj.masse())/(masse()+obj.masse()));
	
	if (distance(obj)<=R+obj.get_rayon()){
		double F1(F*n);
		double F2(obj.get_F()*n);
		if (F1 < 0) {
			ajoute_force(-F1*n);
			obj.ajoute_force(F1*n);
		}
		if (F2 > 0) {
			ajoute_force(F2*n);
			obj.ajoute_force(-F2*n);
		}
		
		double v_star((obj.vit()-vit())*n);
		Vecteur vc(vit()-obj.vit()+v_star*n);
		Vecteur delta_v;
		
		if ((7*nu*(1+alpha)*v_star)>=2*vc.norme()){
			delta_v=lambda*v_star*n-(2*obj.masse())/(7*(masse()+obj.masse()))*vc;
		}
		else {
			delta_v=lambda*v_star*(n-nu*(~vc));
		}
		
		ajoute_vit(delta_v);
		obj.ajoute_vit(-(masse()/obj.masse())*delta_v);
		
		if (test) {
			cout << "   n = " << n << endl;
			cout << "   lambda = " << lambda << endl;
			cout << "   F1n = " << F1 << endl;
			cout << "   F2n = " << F2 << endl;
			cout << "   vstar = " << v_star << endl;
			cout << "   vc = " << vc << endl;
			cout << "   7 mu (1+alpha) vstar = " << 7*nu*(1+alpha)*v_star << endl;
			cout << "   2*vc.norme() = " << 2*vc.norme() << endl;
			cout << "   dv = " << delta_v << endl;
		}
	}
}	

double ObjetMobile::distance(const ObjetMobile& obj) const {
	return (pos()-obj.pos()).norme()-(R+obj.get_rayon());
}

ObjetMobile::ObjetMobile (double R, double m_vol, Vecteur P, Vecteur dP, double b) 
:R(R), m_vol(m_vol), b(b), P(P), dP(dP)
{ test_size();
  F=(pos().get_vecteur().size());}
	
ObjetMobile::ObjetMobile (double R, double m_vol, double b, int deg)
:R(R), m_vol(m_vol), b(b), P(deg), dP(deg), F(deg)
{}

ostream& ObjetMobile::affiche(ostream& sortie) const{  
	sortie << masse() << " # masse" << endl;
	sortie << get_rayon() << " # rayon" << endl;
	sortie << get_masseVol() << " # masse volumique" << endl;
	return sortie;
}

void ObjetMobile::test_masse() const {
	if (masse() <= 0) {throw erreur_masse;}
}

void ObjetMobile::test_size() const {
	if (P.get_vecteur().size() != dP.get_vecteur().size()) {
		throw erreur_dim;
	}
}

ostream& operator<<(ostream& sortie,  ObjetMobile const& obj){
	return obj.affiche(sortie);
}

void ObjetMobile::test_choc(ObjetMobile& ball) {
	cout << "avant choc:" << endl;
	cout << "   position balle1 = " << pos() << endl;
	cout << "   position balle2 = " << ball.pos() << endl;
	cout << "   distance (entre centres) = " << (P-ball.pos()).norme() << endl;
	cout << "   vitesse  balle1 = " << vit() << endl;
	cout << "   vitesse  balle2 = " << ball.vit() << endl;
	cout << "   force    balle1 = " << F << endl;
	cout << "   force    balle2 = " << ball.get_F() << endl;
	
	cout << endl << "calculs : " << endl;
	agit_sur(ball, true);
	
	cout << "après choc:" << endl;
	cout << "   vitesse  balle1 = " << vit() << endl;
	cout << "   vitesse  balle2 = " << ball.vit() << endl;
	cout << "   force    balle1 = " << F << endl;
	cout << "   force    balle2 = " << ball.get_F() << endl;
}
