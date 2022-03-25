#include "Obstacle.h"

double Obstacle::distance(const ObjetMobile& obj) const{
	return norme(pos-point_plus_proche(obj))-obj.get_rayon();
}
 
void Obstacle::agit_sur(ObjetMobile obj) const{
}

Vecteur Obstacle::point_plus_proche(const ObjetMobile& obj) const{
}
