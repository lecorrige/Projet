#include <iostream>
#include "Integrateur.h"
#include "ObjetMobile.h"
#include "balle.h"
#include "Vecteur.h"
#include "ChampForces.h"
#include "constantes.h"
#include "Systeme.h"
using namespace std;

int main() {
	try {
		ChampForces f({0, -9.81}, false);
		Balle b1(1, 0.127/K, {0, 1}, {1, 2});
		Balle b2(1, 0.127/K, {0, 1}, {0, 2});
		Balle b3(1, 0.127/K, {0, 1}, {0, 0});
		f.agit_sur(b1);
		IntegrateurEulerCromer i(0.01);		
		
		Systeme syst({new Balle(b1), new Balle(b2), new Balle(b2)}, 
					  {}, f, new IntegrateurEulerCromer(i));
		
		for (int i(0); i<5; ++i){
			syst.evolue();
			cout<<syst;
			cout << endl << "######################" << endl;
		}
		
		return 0;
	}
	catch(const string& erreur) {
		cerr << "Erreur : " << erreur << endl;
	}
}
