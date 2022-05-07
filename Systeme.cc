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


Systeme::Systeme (vector<ObjetMobile*> obj,
	              vector<Obstacle*> obs, 
	              vector<ChampForces*> champ_,
	              Integrateur* integre)
: integre(unique_ptr<Integrateur>(integre))
{ for (auto el : obj) {objets.push_back(unique_ptr<ObjetMobile>(el));}
  for (auto el : obs) {obstacles.push_back(unique_ptr<Obstacle>(el));}
  for (auto el : champ_) {champ.push_back(el);}
  for (auto el : champ) {
	  for (auto const& obj : objets) {el->agit_sur(*obj);}
  }                                                                    }
  

Systeme::Systeme(const Systeme& s) 
: Dessinable(s)
{ *this=s; }
	
Systeme& Systeme::operator=(const Systeme& s) {
	objets.clear();
	for (size_t i(0); i<s.objets_size(); ++i) {
		objets.push_back(unique_ptr<ObjetMobile>(s.get_obj(i).copie()));
	}
	obstacles.clear();
	for (size_t i(0); i<s.obstacles_size(); ++i) {
		obstacles.push_back(unique_ptr<Obstacle>(s.get_obs(i).copie()));
	}
    champ = s.get_champ();
	if(s.test_integrateur()) {
		integre=unique_ptr<Integrateur>(s.get_int().copie());
	} else {integre=nullptr;}
}

ostream& operator<<(ostream& sortie, Systeme const& syst){
	sortie << "Le systeme est constitué de :" << endl << endl;
	sortie << "objets mobiles :" << endl << endl;
	syst.afficher_obj(sortie) << endl;
	sortie << "obstacles :" << endl << endl;
	syst.afficher_obs(sortie) << endl;
	syst.afficher_champ(sortie) << endl;
	if (syst.test_integrateur()) {sortie << syst.get_int() << endl;}
	return sortie;
}

ostream& Systeme::afficher_obj(ostream& sortie) const {
   if (not objets.empty()) {
	   for (auto const& el : objets) {
		el->affiche(sortie);
		sortie << endl;
	  }
  } else {sortie << erreur_objet << endl;}
	return sortie;
}

ostream& Systeme::afficher_obs(ostream& sortie) const {
	if (not obstacles.empty()) {
		for (auto const& el : obstacles) {
		   el->affiche(sortie);
		   sortie << endl;
	    }
	} else {sortie << erreur_obstacle << endl;}
	return sortie;
}

ostream& Systeme::afficher_champ(ostream& sortie) const {
   if (not champ.empty()) {
	  for (auto el : champ) {
		sortie << *el << endl;
	  }
	}
	return sortie;
}

void Systeme::ajouter (ObjetMobile const& obj) {
	objets.push_back(unique_ptr<ObjetMobile>(obj.copie()));
}

void Systeme::ajouter (Obstacle const& obs) {
	obstacles.push_back(unique_ptr<Obstacle>(obs.copie()));
}

void Systeme::ajouter (ChampForces& ch) {
	champ.push_back(&ch);
	for (auto const& el : objets) {ch.agit_sur(*el);}
}

void Systeme::ajouter (Integrateur const& in) {
	integre=unique_ptr<Integrateur>(in.copie());
}

void Systeme::evolue(){
	for (auto const& obj : objets) {
		for (auto const& obs : obstacles) {
			if (obs->distance(*obj) <= 0.0) {
				obs->agit_sur(*obj);
				for (auto champ_ : champ) {   //a revoir pas forcement
					champ_->agit_sur(*obj);
				}
			}
		}
	}
	for (size_t i(0); i<objets.size()-1; ++i) {
		for (size_t j(i+1); j<objets.size(); ++j) {
			if (objets[i]->distance(*objets[j]) <= 0.0) {
				objets[i]->agit_sur(*objets[j]);
			}
		}
	}
	for (auto const& el : objets){   //est ce que evolue même si choc ?
		integre->evolue(*el);
	}
}

const Integrateur& Systeme::get_int() const {
	if (test_integrateur()) {return *integre;}
	else {throw erreur_integrateur;}
}

ObjetMobile& Systeme::get_obj(int i) const {
	if (objets[i]!=nullptr) {return *objets[i];}

	else {throw erreur_objet;}
}

Obstacle& Systeme::get_obs(int i) const {
	if (obstacles[i]!=nullptr) {return *obstacles[i];}
	else {throw erreur_obstacle;}
}

