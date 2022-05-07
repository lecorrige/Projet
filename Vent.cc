#include "Vent.h"
#include "Vecteur.h"
#include "Objet.h"

Vent::Vent(Vecteur o, Vecteur n, double l, double L,
		   double p, Vecteur v, bool po)
:ChampForces(v,po),origine(o), normale(n), 
 largeur(l), longueur(L), profondeur(p)
{}


