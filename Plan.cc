#include "Plan.h"
#include "Obstacles.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include <iostream>
using namespace std;


Plan::Plan(Vecteur pos, Vecteur norm)
:Obstacle(pos)
{n=(~norm);}

Vecteur Plan::point_plus_proche(const ObjetMobile& obj) const{
	return obj.pos()+((pos-obj.pos())*n)*n;
}

ostream& Plan::affiche(std::ostream& sortie) const {
	sortie << "un mur plan" << endl;
	sortie << pos << " # origine plan" << endl;
	sortie << n << " # normale plan" << endl;
	return sortie;
}

Plan* Plan::copie() const{
	return new Plan(*this);
}
