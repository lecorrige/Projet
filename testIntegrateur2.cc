#include <iostream>
#include "Integrateur.h"
#include "ObjetMobile.h"
#include "balle.h"
#include "Vecteur.h"
#include "ChampForces.h"
#include "constantes.h"
using namespace std;

void test(ObjetMobile& b, Integrateur const& integ, int n);

int main() {
  try {
	IntegrateurEulerCromer i(0.01);  
	  
    ChampForces f;
	cout << "Nous avons :" << endl;
	cout << f << endl;
	
	Balle b1(0.2, 3, {0, 0, 0}, {0, 0.1, 0.2});
	f.agit_sur(b1);
	cout << b1 << endl;
	
	test(b1, i, 4);
	
	return 0;
  }
  catch (const string& erreur) {
	  cerr << "Erreur : " << erreur << endl;
  }
}


void test(ObjetMobile& b, Integrateur const& integ, int n) {
	for (int i(1); i<=n; ++i) {
		integ.evolue(b);
	    cout << "L'intégration " << i << " donne: " << endl;
	    cout << b << endl;     //voir affichage
	}
}
	    
