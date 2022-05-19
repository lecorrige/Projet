#include "Ressort.h"

using namespace std;

Ressort::Ressort(double R, double m_vol, Vecteur P, Vecteur dP, 
				 double k, Vecteur d, double b)
: ObjetMobile (R, m_vol, P, dP, b), k(k), d(d)
{}

Vecteur Ressort::evolution() const {
	Vecteur Fr(-k*pos().norme()*d);
	Vecteur Ff(-b*vit().norme()*d);
	return (F+Ff+Fr)/masse();
}

void Ressort::ajoute_force(Vecteur const& df) {
	F+=df;
	F=(F*d)*d;
}

Vecteur Ressort::pos() const { return O+P.norme()*d; }

Vecteur Ressort::vit() const { return dP.norme()*d; }
