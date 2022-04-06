#include <iostream>
#include <memory>
#include "Systeme.h"
#include "ObjetMobile.h"
#include "balle.h"
#include "Pendule.h"
#include "Obstacles.h"
#include "Plan.h"
#include "Brique.h"
#include "ChampForces.h"

using namespace std;


int main() {
	try {
		ChampForces f(g, false);
		Balle b1(0.05111, 3, {0, 0, 0.3}, {0, 0.8, 2});
		f.agit_sur(b1);
		Pendule p1(0.05, 190.985931710274, 0.2, 0.005, {1.5}, {-0.5}, {0,1,0}, {0, 1.4, 0.45});
		f.agit_sur(p1);
		Plan pl1((3), {0,0,1});
		
		Systeme s({new Balle(b1), new Pendule(p1)}, {new Plan(pl1)}, f);
		cout << s << endl;
	}
	catch (const string& erreur) {
		cerr << "Erreur : " << erreur << endl;
	}
	 return 0;
 }
