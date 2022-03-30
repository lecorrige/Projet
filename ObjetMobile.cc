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

/*void ObjetMobile::agit_sur(ObjetMobile& obj){
	//plus tard
}

double ObjetMobile::distance(const ObjetMobile& obj) const {
	//plus tard polymorphysme
}*/

ObjetMobile::ObjetMobile (double R, double m_vol, Vecteur P, Vecteur dP, double b) 
:R(R), m_vol(m_vol), b(b), P(P), dP(dP), F(3)
{ test_size();}

ObjetMobile::ObjetMobile (Vecteur P, Vecteur dP)
:R(0), m_vol(0), b(0), P(P), dP(dP), F(3)
{test_size();}	
	
ObjetMobile::ObjetMobile (double R, double m_vol, double b, int deg)
:R(R), m_vol(m_vol), b(b), P(deg), dP(deg), F(3)
{}

ostream& operator<<(ostream& sortie, ObjetMobile const& obj) {  //voir surcharge affichage
	sortie << obj.masse() << " # masse" << endl;
	sortie << obj.get_rayon() << " # rayon" << endl;
	sortie << obj.get_masseVol() << " # masse volumique" << endl;
	sortie << obj.get_force() << " # force" << endl;
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
