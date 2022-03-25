#include <iostream>
#include "ObjetMobile.h"
#include "balle.h"
#include "ChampForces.h"
#include "constantes.h"
using namespace std;

int main() {
	ChampForces f;
	cout << "Nous avons :" << endl;
	cout << "un champ de force :" << endl;
	cout << f << endl;
	
	Balle b1(0.2, 3, {1, 2, 3}, {0, 0.1, 0.2});
	Balle b2(0.1, 1.1, {-1, 1.2, 1.3}, {0, 0.1, 0});
	f.agit_sur(b1);
	f.agit_sur(b2);
	cout << "une balle : " << endl;
	cout << b1 << endl;
	cout << "et une autre balle : " << endl;
	cout << b2 << endl;
	
	Balle b_nul;
	cout << "une balle nulle : " << endl;
	cout << b_nul << endl;
	
	return 0;
}
