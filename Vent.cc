#include "Vent.h"
#include "Vecteur.h"
#include "Objet.h"

Vent(Vecteur o, Vecteur n, double l, double L,
		 double p, Vecteur v=g, bool p=true)
:ChampForces(v,p),origine(o), normale(n), 
 largeur(l), longueur(L), profondeur(p)
{}

bool Vent::est_dans(ObjetMobile const& obj) const{
	return ((((origine-obj.pos())*normale)>0) and 
			(((origine-obj.pos())*normale)<profondeur) and
			(((origine-obj.pos())*~largeur)>0) and
			(((origine-obj.pos())*~largeur)<largeur) and
			(((origine-obj.pos())*~longueur)>0) and
			(((origine-obj.pos())*~longueur)<longueur));
}
