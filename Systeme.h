#pragma once

#include <vector>
#include <memory>
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "Obstacles.h"
#include "ChampForces.h"

class Systeme{
public:
    Systeme (std::vector<ObjetMobile*> const& obj,
	         std::vector<Obstacle*> const& obs, ChampForces, 
	         Integrateur*); //rajouter integrateur
	ChampForces get_champ() const {return *champ;}
	std::ostream& afficher_obj(std::ostream& sortie) const;
	std::ostream& afficher_obs(std::ostream& sortie) const;
	void ajouter_objets (vector<ObjetMobile*> const& obj);
	void ajouter_objets (vector<Obstacle*> const& obj);
	void evolue();
	
private:
	std::vector<std::unique_ptr<ObjetMobile>> objets;
	std::vector<std::unique_ptr<Obstacle>> obstacles;
	std::unique_ptr<ChampForces> champ;
	std::unique_ptr<Integrateur> integre;
};

std::ostream& operator<<(std::ostream& sortie, Systeme const& syst);
