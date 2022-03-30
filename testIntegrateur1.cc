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
		ChampForces f({0, -9.81}, false);
		Balle b1(1, 0.127/K, {0, 1}, {1, 2});
		Balle b2(1, 0.127/K, {0, 1}, {0, 2});
		Balle b3(1, 0.127/K, {0, 1}, {0, 0});
		f.agit_sur(b1);
		IntegrateurEulerCromer i(0.01);
		IntegrateurEulerCromer j(0.02);
		test(b1, i, 5);
		f.agit_sur(b2);
		cout << endl << "######################" << endl;
		test(b2, i, 5);
		f.agit_sur(b3);
		cout << endl << "######################" << endl;
		test(b3, j, 5);
		
		return 0;
	}
	catch(const string& erreur) {
		cerr << "Erreur : " << erreur << endl;
	}
}
	


void test(ObjetMobile& b, Integrateur const& integ, int n) {
	double t(0);
	cout << b << endl;
	for (int i(1); i<=n; ++i) {
		integ.evolue(b);
		t+=integ.get_dt();
	    cout << "=============================" << endl;
	    cout << "t = " << t << endl;
	    cout << b.get_P() << " # parametre" << endl;
	    cout << b.get_dP() << " # vitesse" << endl;
	}
}
	    
	
