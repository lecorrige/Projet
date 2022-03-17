#include <iostream>
#include <vector>
#include "Vecteur.h"
using namespace std;

void Vecteur::test_add(Vecteur const& v) const {
	Vecteur u(addition(v));
	cout << "( ";
	affiche();
	cout << ") + ( ";
	v.affiche();
	cout << ") = ( ";
	u.affiche();
	cout << ")" << endl;
}

int main () {
	Vecteur substract;
	Vecteur opp;
	Vecteur scal;
	Vecteur vec;
	double k;
	/* Cette partie
	* (1) pourrait être écrite autrement, par exemple avec des
	* manipulateurs (set_coord()) ;
	* (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
	*/
	// v1 = (1.0, 2.0, -0.1)
	Vecteur vect1({1.0, 0.0, -0.1});
	vect1.set_coord(1, 2.0); // pour tester set_coord()
	
	// v2 = (2.6, 3.5, 4.1)
	Vecteur vect2({2.6, 3.5, 4.1});
	
	Vecteur vect3(vect1);
	
	cout << "Vecteur 1 : ";
	vect1.affiche();
	cout << endl;
	
	cout << "Vecteur 2 : ";
	vect2.affiche();
	cout << endl;
	
	cout << "Le vecteur 1 est ";
	if (vect1.compare(vect2)) {
		cout << "égal au";
	} else {
		cout << "différent du";
	}
	cout << " vecteur 2," << endl << "et est ";
	if (not vect1.compare(vect3)) {
		cout << "différent du";
	} else {
		cout << "égal au";
	}
	cout << " vecteur 3." << endl;
	
	Vecteur add({3.6, 5.5, 4.0});
	vect1.test_add(vect2);
	
	Vecteur nul({0, 0, 0});
	vect1.test_add(nul);  
	
	vect3=vect1.addition(nul);
	if (vect1.compare(vect3)) {
		cout<<"l'addition avec 0 fonctionne"<<endl;
	}
	else{ cout<<"pb add 0"<<endl; }
	
	substract.augmente(-1.6); substract.augmente(-1.5); substract.augmente(-4.2); 
	
	vect3=vect1.soustraction(vect2);
	if (substract.compare(vect3)) {
		cout<<"la soustraction fonctionne"<<endl;
	}
	else{ cout<<"pb substract"<<endl; }
	vect1.affiche();
	vect3.affiche();
	substract.affiche();
	
	opp.augmente(-1.0); opp.augmente(-2.0); opp.augmente(0.1);
	vect3=vect1.oppose();
	if (opp.compare(vect3)) {
		cout<<"l'oppose fonctionne"<<endl;
	}
	else{ cout<<"pb opp"<<endl;
		vect1.affiche();
		vect3.affiche();
		opp.affiche(); }
	
	scal.augmente(3.0); scal.augmente(6.0); scal.augmente(-0.3);
	
	vect3=vect1.mult(3);
	if (scal.compare(vect3)) {
		cout<<"la mult par scalaire fonctionne"<<endl;
	}
	else{ cout<<"pb mult scalaire"<<endl; }
	
	
	k=vect1.prod_scal(vect2);
	if (k==9.19) {
		cout<<"le produit scalaire fonctionne"<<endl;
	}
	else{ cout<<"pb prod scalaire"<<endl; }
	
	vec.augmente(8.55); vec.augmente(-4.36); vec.augmente(-1.7);
	vect3=vect1.prod_vect(vect2);
	if (vec.compare(vect3)) {
		cout<<"la mult vectoriel fonctionne"<<endl;
	}
	else{ cout<<"pb mult vectoriel"<<endl; }
	
	double n(5.01);
	double m(vect1.norme2());
	if (n-m<= 1e-10) {
		cout<<"la norme fonctionne"<<endl;
	}
	else{ cout<<"pb norme"<<endl; }
	
	return 0;
}
