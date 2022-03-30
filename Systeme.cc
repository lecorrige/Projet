#include "Systeme.h"
#include <ostream>
#include <vector>
#include <memory>
using namespace std;

ostream& operator<<(ostream& sortie, Systeme const& syst){
	sortie << "Le systeme est constitué de :" << endl << endl;
	sortie << "objets mobiles :" << endl << endl;
	sortie << syst.afficher_obj(sortie) << endl;
	sortie << syst.afficher_obs(sortie) << endl;
	sortie << syst.get_champ() << endl;
	return sortie;
}

ostream& Systeme::afficher_obj(ostream& sortie){
	 for (auto el : objets) {
		sortie << *el;
	}
	return sortie;
}

ostream& Systeme::afficher_obs(ostream& sortie){
	 for (auto el : obstacles) {
		sortie << *el;
	}
	return sortie;
}
