#include "IntegrateurNewmark.h"
#include "Vecteur.h"
#include <cmath>

using namespace std;

IntegrateurNewmark::IntegrateurNewmark(double e, double dt)
:Integrateur(dt), epsilon(e)
{}

void IntegrateurNewmark::evolue(ObjetMobile& obj) const { 
	Vecteur dPn1(obj.get_dP());
	Vecteur Pn1(obj.get_P());
	Vecteur dPn(dPn1);
	Vecteur Pn(Pn1);
	Vecteur s(obj.evolution());
	obj.set_vit(dPn);
	obj.set_pos(Pn);
	Vecteur q;
	Vecteur r;
	do
	{
		q=Pn;
		r=obj.evolution();
		dPn=dPn1+dt*(r+s)/2;
		Pn=Pn1+dt*dPn1+pow(dt,2)*(r/2+s)/3;
	} while ((Pn-q).norme()>=epsilon);
	
};

IntegrateurNewmark* IntegrateurNewmark::copie() const {
	return new IntegrateurNewmark(*this);
}

ostream& IntegrateurNewmark::affiche_nom(ostream& sortie) const { 
	sortie<<"Integrateur Newmark avec epsilon :"<<epsilon<<endl;
	return sortie; 
}
