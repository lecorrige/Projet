#include <cmath>
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "Pendule.h"
#include "constantes.h"

using namespace std;


Vecteur Pendule::evolution() const { 
	test_masse();
	return {(cos(P.get_vecteur()[0])*F*d - sin(P.get_vecteur()[0])*F*(~g) 
	         - b*dP.get_vecteur()[0]/L)*(1/(masse()*L))} ;
}

Pendule::Pendule (double R, double m_vol, double L, double b, Vecteur P, Vecteur dP, Vecteur d, Vecteur O)
: ObjetMobile (R, m_vol, P, dP, b), L(L), O(O), d(d)
{F=(pos().get_vecteur().size());
 test_orth(); 
 test_tige();                  }

Pendule::Pendule (double R, double m_vol, double L, double b, int deg)
: ObjetMobile (R, m_vol, b, deg), L(L), O(3), d(3)
{F=(pos().get_vecteur().size());
 test_orth();
 test_tige();                   } 

ostream& Pendule::affiche(ostream& sortie) const{
	sortie<<"un pendule "<<endl;
	ObjetMobile::affiche(sortie);
	sortie<<get_L()<<" # longueur pendule"<<endl;
	sortie<<get_b()<<" # frottement pendule"<<endl;
	sortie<<get_O()<<" # origine pendule" << endl;
	sortie<<get_d()<<" # direction pendule"<<endl;
	sortie<<get_P()<<" # theta pendule" << endl;
	sortie<<get_dP()<<" # theta point pendule"<<endl;
	sortie<<pos_masse()<<" # position bout pendule"<<endl;
	sortie<<vit_masse()<<" # vitesse bout pendule"<<endl;
	sortie<<force_masse()<<" # force bout pendule" << endl;
	sortie<<evolution()<<" # f() pendule" << endl;
	
	return sortie; 
}

Vecteur Pendule::pos_masse() const {
	return (O + L*cos(P.get_vecteur()[0])*(~g) + L*sin(P.get_vecteur()[0])*d);
}

Vecteur Pendule::vit_masse() const {
	return (L*dP.get_vecteur()[0]*(cos(P.get_vecteur()[0])*d - sin(P.get_vecteur()[0])*(~g)));
}

Vecteur Pendule::force_masse() const {
	Vecteur x1(evolution().get_vecteur()[0]*(cos(P.get_vecteur()[0])*d-sin(P.get_vecteur()[0])*(~g)));
	Vecteur x2(pow(dP.get_vecteur()[0], 2)*(sin(P.get_vecteur()[0])*d+cos(P.get_vecteur()[0])*(~g)));
	return masse()*L*(x1-x2);
}

Pendule* Pendule::copie() const {
	return new Pendule(*this);
}

void Pendule::test_orth() const {
	if (g*d != 0) {throw erreur_orth;}
}

void Pendule::test_tige() const {
	if (L-0<precision) {throw erreur_tige;}
}

void Pendule::ajoute_force(Vecteur const& df) {
	F += df;
}
