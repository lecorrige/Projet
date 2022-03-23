#pragma once
#include "Vecteur.h"
#include "balle.h"
	
class ChampForces{
	public:
	void agit_sur(Balle balle);
	
	private:
	Vecteur intensite;
	
};
