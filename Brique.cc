#include "Brique.h"
#include "Plan.h"
#include "Vecteur.h"
#include "Obstacle.h"
#include <vector>
using namespace std;

Brique::Brique(Vecteur pos, Vecteur L, Vecteur l, double h)
:Obstacle (pos), L(L), l(l), h(h)
{
	if (L*l==0){
		l-=l*(~L);
	}
}

Vecteur Brique::proche_plan_fini(const ObjetMobile& obj, Vecteur pos, 
								 double L, Vecteur eL, 
								 double l, Vecteur el) const
{
	Vecteur L_vec(L*eL);
	Vecteur l_vec(l*el);
	
	Vecteur n(eL^el);
	
	Plan inf(pos,n);
	Vecteur x2(inf.point_plus_proche(obj));
	
	Vecteur xkL((x2-pos)*eL);
	Vecteur xkl((x2-pos)*el);
	
	if (xkL.norme()>L) { x2-=(xkL-L_vec)*eL; }
	else if (xkL.norme()<0) { x2-=xkL*eL; }
	
	if (xkl.norme()>l) { x2-=(xkl-l_vec)*el; }
	else if (xkl.norme()<0) { x2-=xkl*el; }
	
	return x2;
}

Vecteur Brique::min(vector<Vecteur> x){
	Vecteur m(x[0]);
	for (size_t i(0); i<x.size(); ++i){
		for (size_t j(i); j<x.size(); ++j){
			if (x[i].norme()<m.norme()) { m=x[i]; }
		}
	}
	return m;
}

Vecteur Brique::point_plus_proche(const ObjetMobile& obj) const
{
	Vecteur const eL(~L);
	Vecteur const el(~l);
	Vecteur const n(eL^el);
	
	Vecteur x1(proche_plan_fini(obj, pos, L.norme(), eL, l.norme(), el));
	Vecteur x2(proche_plan_fini(obj, pos, h, -n, L.norme(), eL));
	Vecteur x3(proche_plan_fini(obj, pos, l.norme(), el, h, -n));
	Vecteur x4(proche_plan_fini(obj, pos+L, h, -n, l.norme(), el));
	Vecteur x5(proche_plan_fini(obj, pos+l, L.norme(), eL, h, -n));
	Vecteur x6(proche_plan_fini(obj, pos-h*n, l.norme(), el, L.norme(), eL));
	
	vector<Vecteur> a({x1, x2, x3, x4, x5, x6});
	
	return min(a);
}
