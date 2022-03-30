#include <iostream>
#include "ChampForces.h"
#include "Pendule.h"
#include "Integrateur.h"
#include "constantes.h"
#include "Vecteur.h"

using namespace std;

void test(ObjetMobile& b, Integrateur const& integ, int n);

int main() {
  try {	
	cout << "Nous avons :" << endl;
	ChampForces f(g, false);
	cout << f << endl;
	
	Pendule p1(1, 0.1/K, 0.2, 0.005, {0.4}, {0}, {0, 1, 0}, {0, 2, 1});
	f.agit_sur(p1);
	IntegrateurEulerCromer i(0.01);
	test(p1, i, 5);
	
	Pendule p2;
	cout << p2 << endl;
	
	return 0;
  }
  catch (const string& erreur) {
	  cerr << "Erreur : " << erreur << endl;
  }
}

void test(ObjetMobile& p, Integrateur const& integ, int n) {
	cout << p << endl;
	for (int i(1); i<=n; ++i) {
		integ.evolue(p);
	    cout << "=============================" << endl;
	    cout << "l'integration " << i << " donne :" << endl;
	    cout << p << endl;
	}
}
