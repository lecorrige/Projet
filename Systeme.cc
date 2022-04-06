#include "Systeme.h"
#include "ChampForces.h"
#include "ObjetMobile.h"
#include "balle.h"
#include "Pendule.h"
#include "Obstacles.h"
#include "Plan.h"
#include "Brique.h"
#include <ostream>
#include <vector>
#include <memory>
using namespace std;


Systeme::Systeme (vector<ObjetMobile*> const& obj,
	              vector<Obstacle*> const& obs, ChampForces champ)
: champ(unique_ptr<ChampForces>(new ChampForces(champ)))
{ ajouter_objets(obj);
  ajouter_objets(obs); }
		

ostream& operator<<(ostream& sortie, Systeme const& syst){
	sortie << "Le systeme est constitué de :" << endl << endl;
	sortie << "objets mobiles :" << endl << endl;
	syst.afficher_obj(sortie) << endl;
	sortie << "obstacles :" << endl << endl;
	syst.afficher_obs(sortie) << endl;
	sortie << syst.get_champ() << endl;
	return sortie;
}

ostream& Systeme::afficher_obj(ostream& sortie) const {
   for (auto const& el : objets) {
		el->affiche(sortie);
		cout << endl;
	}
	return sortie;
}

ostream& Systeme::afficher_obs(ostream& sortie) const {
	 for (auto const& el : obstacles) {
		el->affiche(sortie);
	}
	return sortie;
}

void Systeme::ajouter_objets (vector<ObjetMobile*> const& obj) {
	for (auto el : obj) {
		objets.push_back(unique_ptr<ObjetMobile>(el));
	}
}

void Systeme::ajouter_objets (vector<Obstacle*> const& obs) {
	for (auto el : obs) {
		obstacles.push_back(unique_ptr<Obstacle>(el));
	}
}

