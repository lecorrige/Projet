#include "Brique.h"
#include <iostream>

using namespace std;

int main() {
try {
	Balle bye(0.5, 0.1/k, {0,5,0,5,2}, {0,0,-1});
	Brique b({0,0,0}, {0,0,1}, {1,0,0}, 1);
	IntegrateurEulerCromer i;
	TextViewer t;
	Systeme s(&bye, &b, &i);
	
	s.simuler(t);
	
	bye.set_pos({0.5,2,0.5});
	bye.set_vit({0,-1,0});
	
	s.simuler(t);
	
	bye.set_pos({2,0.5,0.5});
	bye.set_vit({-1,0,0});
	
	s.simuler(t);

	
	return 0; 
}
catch (const string& erreur) {
	cerr << "Erreur : " << erreur << endl;
   }
}

