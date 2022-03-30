#include <cmath>
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "Pendule.h"
#include "constantes.h"
#include <cmath>

using namespace std;


Vecteur Pendule::evolution() const { 
	return {(cos(P.get_vecteur()[0])*F*d - sin(P.get_vecteur()[0])*F*(~g) 
	         - b*dP.get_vecteur()[0]/L)*(1/(masse()*L))} ;
}

Pendule::Pendule (double R, double m_vol, double L, double b, Vecteur P, Vecteur dP, Vecteur d, Vecteur O)
: ObjetMobile (R, m_vol, P, dP, b), L(L), O(O), d(d)
{}

Pendule::Pendule (double R, double m_vol, double L, double b, int deg)
: ObjetMobile (R, m_vol, b, deg), L(L), O(3), d(3)
{} 

ostream& operator<<(ostream& sortie, Pendule const& p){
	sortie<<"un pendule "<<endl;
	sortie<<p.masse()<<" # masse pendule"<<endl;
	sortie<<p.get_L()<<" # longueur pendule"<<endl;
	sortie<<p.get_b()<<" # frottement pendule"<<endl;
	sortie<<p.get_O()<<" # origine pendule" << endl;
	sortie<<p.get_d()<<" # direction pendule"<<endl;
	sortie<<p.get_P()<<" # theta pendule" << endl;
	sortie<<p.get_dP()<<" # theta point pendule"<<endl;
	sortie<<p.evolution()<<" # f() pendule" << endl;
	sortie<<p.pos_masse()<<" # position bout pendule"<<endl;
	sortie<<p.vit_masse()<<" # vitesse bout pendule"<<endl;
	sortie<<p.get_F()<<" # force exercee sur le pendule"<<endl;
	
	return sortie; 
}

Vecteur Pendule::pos_masse() const {
	return (O + L*cos(P.get_vecteur()[0])*(~g) + L*sin(P.get_vecteur()[0])*d);
}

Vecteur Pendule::vit_masse() const {
	return (L*dP.get_vecteur()[0]*(cos(P.get_vecteur()[0])*d - sin(P.get_vecteur()[0])*(~g)));
}
