#include "Ventilateur.h"
#include "constantes.h"
#include <cmath>

Ventilateur::Ventilateur(Vent const& v, Brique const& b)
:Compose({&v, &b})
{
	if (v.get_O()!=b.get_O()){ objets[0]->set_O(b.get_O()); }
	if (v.get_l()!=b.get_l()){ objets[0]->set_l(b.get_l()); }
	if (v.get_L()!=b.get_L()){ objets[0]->set_L(b.get_L()); }
}

void Ventilateur::agit_sur(ObjetMobile& obj) {
	if (est_dans(obj)){
		Vecteur F(Q*pow(objets[0].get_intensite()[0],2)*obj.get_rayon()*objets[0]->get_n());
		obj.ajoute_force(F);
	}
}

bool Ventilateur::est_dans(ObjetMobile const& obj) const{
	return ((((objets[0]->get_O()-obj.pos())*objets[0]->get_n())>0) and 
			(((objets[0]->get_O()-obj.pos())*objets[0]->get_n())<objets[0]->get_p()) and
			(((objets[0]->get_O()-obj.pos())*(~(objets[1]->get_l()))>0) and
			(((objets[0]->get_O()-obj.pos())*(~(objets[1]->get_l())))<<objets[0]->get_L()) and
			(((objets[0]->get_O()-obj.pos())*(~(objets[1]->get_L())))>0) and
			(((objets[0]->get_O()-obj.pos())*(~(objets[1]->get_L())))<objets[0]->get_l())));
}
