#pragma once

#include <vector>
#include <memory>
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "Obstacle.h"
#include "ChampForces.h"

class Systeme{
public:
	ChampForces get_champ() {return champ;}
	std::ostream& afficher_obj(std::ostream& sortie);
	std::ostream& afficher_obs(std::ostream& sortie);
	
private:
	std::vector<std::unique_ptr<ObjetMobile>> objets;
	std::vector<std::unique_ptr<Obstacle>> obstacles;
	Integrateur integre;
	ChampForces champ;
};

std::iostream& operator<<(std::iostream& sortie, Systeme const& syst);
