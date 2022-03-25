#include "Brique.h"
#include "Plan.cc"
#include "Vecteur.cc"
using namespace std;

Brique::Brique(Vecteur O, Vecteur L, Vecteur l, double h)
:Obstacle (O), L(L), l(l), h(h)
{
	if (L*l==0){
		l-=l*unitaire(L);
	}
}

Vecteur Brique::proche_plan_fini(const ObjetMobile& obj) const
{
	Vecteur eL(~L);
	Vecteur el(~l);
	Vecteur n(eL^el);
	
	Plan inf(pos,n);
	Vecteur x2(inf.point_plus_proche(obj));
	
	double xkL((x2-pos)*eL);
	double xkl((x2-pos)*el);
	
	if (xkL>L) { x2-=(xkL-L)*eL; }
	else if (xkL<0) { x2-=xkL*eL; }
	
	if (xkl>l) { x2-=(xkl-l)*el; }
	else if (xkl<0) { x2-=xkl*el; }
	
	return x2;
}

Vecteur Brique::point_plus_proche(const ObjetMobile& obj) const
{
}
