#include <iostream>
#include <string>
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "constantes.h"
#include <cmath>

using namespace std;

double ObjetMobile::masse() const {
	return (m_vol*pow(R, 3)*K);
}

void ObjetMobile::agit_sur(ObjetMobile& obj){
	Vecteur n(~(pos()-obj.pos()));
	double lambda(((1+alpha)*obj.masse())/(masse()+obj.masse()));
	
	if (distance(obj)<=R+obj.get_rayon()){
		double F1(F*n);
		double F2(obj.get_F()*n);
		if (F1<0){
			ajoute_force(-F1);
			obj.ajoute_force(F1);
		}
		if (F2>0){
			ajoute_force(F2);
			obj.ajoute_force(-F2);	
		}
		
		double v_star((obj.vit()-vit())*n);
		Vecteur vc(vit()-obj.vit()+v_star*n);
		
		Vecteur delta_v;
		
		if ((7*nu*(1+alpha)*v_star)>=2*vc){
			delta_v=lambda*v_star*n-(2*obj.masse())/(7*(masse()+obj.masse()))*vc;
		}
		else {
			delta_v=lambda*v_star*(n-nu*(~vc));
		}
		
		ajoute_vit(delta_v);
		obj.ajoute_vit(-(masse()/obj.masse())*delta_v);
	}
}	
/* A RAJOUTER DANS OBSTACLE !!!!!!
void Obstacle::agit_sur(ObjetMobile& obj){
	Vecteur n(~(pos()-obj.pos()));
	double lambda(1+alpha);
	
	if (distance(obj)<=obj.get_rayon()){
		double F1(F*n);
		if (F1<0){
			ajoute_force(-F1);
		}
		
		double v_star((-obj.vit())*n);
		Vecteur vc(obj.vit())+v_star*n);
		
		Vecteur delta_v;
		
		if ((7*nu*(1+alpha)*v_star)>=2*vc){
			delta_v=lambda*v_star*n-2/7*vc;
		}
		else {
			delta_v=lambda*v_star*(n-nu*(~vc));
		}
		
		ajoute_vit(delta_v);
	}
}
*/

double ObjetMobile::distance(const ObjetMobile& obj) const {
	return (pos()-obj.pos()).norme()-(R+obj.get_R());
}

ObjetMobile::ObjetMobile (double R, double m_vol, Vecteur P, Vecteur dP, double b) 
:R(R), m_vol(m_vol), b(b), P(P), dP(dP), F(3)
{ test_size();}

ObjetMobile::ObjetMobile (Vecteur P, Vecteur dP)
:R(0), m_vol(0), b(0), P(P), dP(dP), F(3)
{test_size();}	
	
ObjetMobile::ObjetMobile (double R, double m_vol, double b, int deg)
:R(R), m_vol(m_vol), b(b), P(deg), dP(deg), F(3)
{}

ostream& ObjetMobile::affiche(ostream& sortie) const{  //voir surcharge affichage
	sortie << masse() << " # masse" << endl;
	sortie << get_rayon() << " # rayon" << endl;
	sortie << get_masseVol() << " # masse volumique" << endl;
	sortie << get_force() << " # force" << endl;
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
