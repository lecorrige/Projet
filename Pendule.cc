#include <cmath>
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "Pendule.h"
#include "constantes.h"

using namespace std;


Vecteur Pendule::evolution() const { 
	Vecteur theta_2_point((cos(P.norme())*(F*d)-sin(P.norme())*F*(~g)-(frottement*dP.norme())/L)/(masse()*L)) ;
	
	/*Vecteur v1{0,0,cos(P)};
	pos_bout=O+L*v1+L*sin(P)*d;
	
	Vecteur v2{0,0,-sin(P)};
	vit=m*L*(theta_2_point*(cos(P)*d-v2)-pow(dP,2)*(sin(theta)*d+v1));*/
	
	return theta_2_point;
}

Pendule::Pendule(double R, double m_vol, Vecteur P, Vecteur dP, Vecteur pos, Vecteur vit, Vecteur F,
				 double L, double frott, Vecteur d, Vecteur pos_bout)
				 
	:ObjetMobile (R, m_vol, P, dP, pos, vit, F), 
	 L(L), frottement(frott), d(d), pos_bout(pos_bout)
{}

ostream& operator<<(ostream& sortie,  Pendule const& p){
	ObjetMobile& o(p);
	sortie<<o;
	sortie<<"un pendule "<<endl;
	sortie<<p.get_fr()<<" # frottement pendule"<<endl;
	sortie<<p.get_d()<<" # direction pendule"<<endl;
	sortie<<p.get_pos_bout()<<" # position bout pendule"<<endl;
	
	return sortie; 
}
