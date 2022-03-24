#pragma once
#include "Vecteur.h"
#include "balle.h"
#include "constantes.h"
#include <ostream>
	
class ChampForces{
public:
    ChampForces (Vecteur v=g);   //constructeur avec pour valeur par défaut g(gravite)
	void agit_sur(Balle& balle);
	Vecteur get_intensite() const {return intensite;}
private:
	Vecteur intensite;    //représente direction et intensité(norme) du champ de force
	
};


std::ostream& operator<<(std::ostream& sortie, ChampForces const& f);
