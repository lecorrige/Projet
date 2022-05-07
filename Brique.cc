#include "Brique.h"
#include "Plan.h"
#include "Vecteur.h"
#include "Obstacles.h"
#include "constantes.h"
#include <vector>
#include <ostream>
using namespace std;

Brique::Brique(Vecteur pos, Vecteur L, Vecteur l, double h)
:Obstacle (pos), L(L), l(l), h(h)
{
	if (L*l!=0){                            //test orthogonalite
		l-= (l*(~L))*(~L);
	}
}

Vecteur Brique::proche_plan_fini(const ObjetMobile& obj, Vecteur origine, 
								 double L, Vecteur eL, 
								 double l, Vecteur el) const
{
	Vecteur n(eL^el);
	
	Plan inf(origine,n);
	Vecteur x2(inf.point_plus_proche(obj));
	
	double xkL((x2-pos)*eL);
	double xkl((x2-pos)*el);
	
	if (xkL>L) { x2-=(xkL-L)*eL; }
	else if (xkL<0) { x2-=xkL*eL; }
	
	if (xkl>l) { x2-=(xkl-l)*el; }
	else if (xkl<0) { x2-=xkl*el; }
	
	return x2;
}

Vecteur Brique::min(vector<Vecteur> const& x, const ObjetMobile& obj) const {
	Vecteur m(x[0]);
	for (size_t i(1); i<x.size(); ++i){
		if ((x[i]-obj.pos()).norme()-(m-obj.pos()).norme() < precision) {
			m=x[i];
		}
	}
	return m;
}

Vecteur Brique::point_plus_proche(const ObjetMobile& obj) const
{
	Vecteur const eL(~L);
	Vecteur const el(~l);
	Vecteur const n(eL^el);
	
	Vecteur x1(proche_plan_fini(obj, pos, L*eL, eL, l*el, el));
	Vecteur x2(proche_plan_fini(obj, pos, h, -n, L*eL, eL));
	Vecteur x3(proche_plan_fini(obj, pos, l*el, el, h, -n));
	Vecteur x4(proche_plan_fini(obj, pos+L, h, -n, l*el, el));
	Vecteur x5(proche_plan_fini(obj, pos+l, L*eL, eL, h, -n));
	Vecteur x6(proche_plan_fini(obj, pos-h*n, l*el, el, L*eL, eL));
	
	vector<Vecteur> a({x1, x2, x3, x4, x5, x6});
	return min(a, obj);
}

ostream& Brique::affiche(ostream& sortie) const {
	sortie << "un mur brique" << endl;
	sortie << pos << " # origine brique" << endl;
	sortie << L << " # longueur brique" << endl;
	sortie << l << " # largeur brique" << endl;
	sortie << h << " # hauteur brique" << endl;
	return sortie;
}

Brique* Brique::copie() const{
	return new Brique(*this);
}

Vecteur Brique::normale(const ObjetMobile& obj) const {
	return face_plus_proche(obj).get_n();
}

Plan Brique::face_plus_proche(const ObjetMobile& obj) const {
	Vecteur ref(point_plus_proche(obj));
	
	Vecteur const eL(~L);
	Vecteur const el(~l);
	Vecteur const n(eL^el);
	
	Plan plan1(pos, n);
	Plan plan2(pos, -el);
	Plan plan3(pos, -eL);
	Plan plan4(pos+L, eL);
	Plan plan5(pos+l, el);
	Plan plan6(pos-h*n, -n);
	vector<Plan> a({plan2, plan3, plan4, plan5, plan6});
	Plan min(plan1);
	for (auto const& el : a) {
		if ((el.point_plus_proche(obj)-ref).norme() < 
		    (min.point_plus_proche(obj)-ref).norme()      ) {min=el;}
	}
	return min;
}
			
