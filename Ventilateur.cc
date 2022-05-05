#include "Ventilateur.h"
#include "constantes.h"
#include <cmath>

Ventilateur(Vent const& v, Brique const& b)
:Compose({&v, &b})
{
	if (v.get_O()!=b.get_O()){ objets[0]->set_O(b.get_O()); }
	if (v.get_l()!=b.get_l()){ objets[0]->set_l(b.get_l()); }
	if (v.get_L()!=b.get_L()){ objets[0]->set_L(b.get_L()); }
}

void agit_sur(ObjetMobile& obj) {
	if (objets[0]->est_dans(obj){
		Vecteur F(Q*pow(objets[0].get_intensite()[0],2)*obj.get_rayon()*normale);
		obj.ajoute_force(F);
	}
}
