#pragma once

#include <vector>
#include <memory>
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "Obstacles.h"
#include "ChampForces.h"
#include "Dessinable.h"


class Systeme : public Dessinable {
public:
    Systeme (std::vector<ObjetMobile*>,
	         std::vector<Obstacle*>, 
	         std::vector<ChampForces*>,
	         Integrateur* = nullptr);  
	Systeme() = default;      //par defaut, on veut un integrateur avec pas de temps 0
	virtual ~Systeme() = default;
	Systeme(const Systeme&);
	Systeme& operator=(const Systeme&);
	Systeme(Systeme&&)                 = delete;
	Systeme& operator=(Systeme&&)      = delete;
	std::ostream& afficher_obj(std::ostream&) const;
	std::ostream& afficher_obs(std::ostream&) const;
	std::ostream& afficher_champ(std::ostream&) const;
	void ajouter(ObjetMobile const&);
	void ajouter(Obstacle const&);
	void ajouter(ChampForces&);
	void ajouter(Integrateur const&);
	void evolue();
	virtual void dessine_sur(SupportADessin& support)override {support.dessine(*this);}
	virtual void param_sur(SupportADessin& support) override {support.param(*this);}
	const Integrateur& get_int() const;
	bool test_integrateur() const {return integre!=nullptr;}
	ObjetMobile& get_obj(int) const;
	Obstacle& get_obs(int) const;
	vector<ChampForces*> get_champ() const {return champ;}  //copie de surface (même zone memoire)
	size_t objets_size() const {return objets.size();}
	size_t obstacles_size() const {return obstacles.size();}
	size_t champ_size() const {return champ.size();}
	
private:
	std::vector<std::unique_ptr<ObjetMobile>> objets;
	std::vector<std::unique_ptr<Obstacle>> obstacles;
	std::vector<ChampForces*> champ;   //ils peuvent être partagés par plusieurs systemes
	std::unique_ptr<Integrateur> integre;
};

std::ostream& operator<<(std::ostream& sortie, Systeme const& syst);
