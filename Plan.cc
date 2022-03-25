#include "Plan.h"
using namespace std;

Plan::Plan(Vecteur O, Vecteur n)
:Obstacle(O), n(n)
{
	if (n!=unitaire(n)) { n=unitaire(n); }
}

Vecteur Plan::point_plus_proche(const ObjetMobile& obj) const{
	Vecteur x1(obj.get_pos());
	Vecteur x2((x1+(pos-x1)*n)*n);
	return x2;
}
