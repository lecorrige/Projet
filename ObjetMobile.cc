#include <iostream>
#include <string>
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "Constantes.h"
#include <cmath>
using namespace std;

double ObjetMobile::masse() const {
	return (m_vol*pow(R, 3)*K);
}

Vecteur ObjetMobile::evolution(){
	return {0};
}

void ObjetMobile::agit_sur(ObjetMobile obj){
	Vecteur force((obj.masse()-4*M_PI*Rho_air*pow(obj.get_rayon(), 3))*g);
	obj.set_f(force);
}

double ObjetMobile::distance(const ObjetMobile& obj){
	Vecteur d(obj.get_pos()-pos);
	return d.norme();
}

ObjetMobile::ObjetMobile (double R, double m_vol, Vecteur P, Vecteur dP,  Vecteur pos, Vecteur vit,  Vecteur F)
:P(P), dP(dP), pos(pos), vit(vit), R(R), m_vol(m_vol), F(F)
{
		if (P.get_vecteur().size()!=dP.get_vecteur().size()){
			throw erreur_dim; //a recuperer
		}
}

ObjetMobile::ObjetMobile ( double R, double m_vol, Vecteur pos, Vecteur vit, Vecteur F, int deg)
:P(deg), dP(deg), pos(pos), vit(vit), R(R), m_vol(m_vol), F(F)
{}

ostream& operator<<(ostream& sortie, ObjetMobile const& obj) {
	sortie<<"Nous avons : "<<endl;
	sortie<<"un champs de force : "<<endl;
	sortie << obj.get_force() << " # intensite" << endl;
	sortie << obj.masse() << " # masse" << endl;
	sortie << obj.get_rayon() << " # rayon" << endl;
	sortie << obj.get_masseVol() << " # masse volumique" << endl;
	sortie << obj.get_pos() << " # position" << endl;
	sortie << obj.get_vit() << " # vitesse" << endl;
	sortie << obj.get_P() <<" # P"<<endl;
	sortie << obj.get_dP() <<" # dP"<<endl;
	sortie << obj.evolution() <<" # f()"<<endl;
	return sortie;
}
