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
	IntegrateurEulerCromer i(0.01);  
	  
    ChampForces f;
	cout << "Nous avons :" << endl;
	cout << f << endl;
	
	Balle b1(0.2, 3, {0, 0, 0}, {0, 0.1, 0.2});
	f.agit_sur(b1);
	cout << b1 << endl;
	
	Systeme syst({b1}, {}, f, new IntegrateurEulerCromer(i));  
	
	for (int i(1); i<=4; ++i){
		syst.evolue();
		cout << "L'intégration " << i << " donne: " << endl;
		cout<<syst;
	}
	
	return 0;
  }
  catch (const string& erreur) {
	  cerr << "Erreur : " << erreur << endl;
  }
}


