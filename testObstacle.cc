#include <iostream>
#include "Obstacles.h"
#include "Plan.h"
#include "Brique.h"
#include "ObjetMobile.h"
#include "balle.h"
#include "ChampForces.h"

using namespace std;

void test(Plan const& plan, Brique const& brique, ObjetMobile const& balle);
void deplace(ObjetMobile& balle, Vecteur const& v);

int main() {
	try {
		cout << "Nous avons :" << endl;
		Plan p(3, {0, 0, 1});
		cout << p << endl;
		
		Brique br({0, 0, 0.5}, {0, -0.6, 0}, {0.8, 0, 0}, 0.5);
		cout << br << endl;
		
		Balle ba(0.2, 3, {1.2, -0.4, 0.3});
		ChampForces f;
		f.agit_sur(ba);
		cout << ba << endl;
		
		test(p, br, ba);
		
		Vecteur v1(1.2, -0.4, 1.3);
		deplace(ba, v1);
		
		test(p, br, ba);
		
		Vecteur v2(0.2, -0.4, 1.3);
		deplace(ba, v2);
		test(p, br, ba);
		
		return 0;
	}
	catch (const string& erreur) {
		cerr << "Erreur : " << erreur << endl;
	}
}

void test(Plan const& plan, Brique const& brique, ObjetMobile const& balle) {
	cout << "tests :" << endl;
	cout << plan.point_plus_proche(balle) << " # point plus proche de plan" << endl;
	cout << plan.distance(balle) << " # distance plan" << endl;
	cout << brique.point_plus_proche(balle) << " # point plus proche brique" << endl;
	cout << brique.distance(balle) << " # distance brique" << endl << endl;
}

void deplace(ObjetMobile& balle, Vecteur const& v) {
	balle.set_P(v);
	cout << "je deplace la balle en : " << v << endl;
	cout << balle << endl;
}
