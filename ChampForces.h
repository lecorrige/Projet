#pragma once
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include <ostream>
	
class ChampForces{
public:
    ChampForces (Vecteur v=g, bool test=true);   //constructeur avec pour valeur par défaut g(gravite)
	void agit_sur(ObjetMobile& obj) const;
	Vecteur get_intensite() const {return intensite;}
private:
	Vecteur intensite;    //représente direction et intensité(norme) du champ de force
	bool poussee;   //pour savoir si l'on doit inclure la poussee d'Archimede dans la formule
};


std::ostream& operator<<(std::ostream& sortie, ChampForces const& f);
