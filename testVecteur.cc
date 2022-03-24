#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "constantes.h"
using namespace std;

void test(Vecteur v1, Vecteur v2, Vecteur v3, char c) {         //fonction pour tester l'addition et la soustraction.
	cout << "(" << v1 << ") " << c << " (" << v2 << ") = (";
	cout << v3 << ")" << endl;
}

int main () {
  try {
	Vecteur vect1(1.0, 0.0, -0.1);
	vect1.set_coord(1, 2.0); // pour tester set_coord()
	
	Vecteur vect2(2.6, 3.5, 4.1);
	
	Vecteur vect3(vect1);
	Vecteur vect4(4);
	
	cout << "Vecteur 1 : " << vect1 << endl;
	cout << "Vecteur 2 : " << vect2 << endl;
	cout << "Vecteur 3 : " << vect3 << endl;
	cout << "Vecteur 4 : " << vect4 << endl;
	
	cout << "Le vecteur 1 est ";
	if (vect1 == vect2) {
		cout << "égal au";
	} else {
		cout << "différent du";
	}
	cout << " vecteur 2," << endl << "et est ";
	if (vect1 != vect3) {
		cout << "différent du";
	} else {
		cout << "égal au";
	}
	cout << " vecteur 3." << endl;
	
	Vecteur v_test(vect1+vect2);
	test(vect1, vect2, v_test, '+'); 
	v_test = vect2+vect1;
	test(vect2, vect1, v_test, '+');
	
	Vecteur v_nul(3);
	v_test = vect1 + v_nul;
	test(vect1, v_nul, v_test, '+');
	v_test = v_nul + vect1;
	test(v_nul, vect1, v_test, '+');
	v_test = vect1 - vect2;
	test(vect1, vect2, v_test, '-');
	v_test = vect2 - vect2;
	test(vect2, vect2, v_test, '-');
	
	Vecteur v_2({1, 2});
	/*v_test = vect2 + v_2;
	test(vect2, v_2, v_test,'+');*/
	v_test = v_2 + vect2;
	test(v_2, vect2, v_test, '+');
	
	cout << "- (" << vect1 << ") = (" << -vect1 << ")" << endl;
	cout << "- (" << vect2 << ") + (" << vect1 << ") = (" << -vect2 + vect1 << ")" << endl;
	cout << "3 * (" << vect1 << ") = (" << 3*vect1 << ")" << endl;
	cout << "(" << vect1 << ") * (" << vect2 << ") = " << vect1*vect2 << endl;
	cout << "(" << vect2 << ") * (" << vect1 << ") = " << vect2*vect1 << endl;
	cout << "(" << vect1 << ") ^ (" << vect2 << ") = (" << (vect1 ^ vect2) << ")" << endl;
	cout << "(" << vect1 << ") * (" << vect1 << ") = " << vect1*vect1 << endl;
	cout << "||" << vect1 << "||² = " << vect1.norme2() << endl;
	cout << "||" << vect1 << "|| = " << vect1.norme() << endl;
	cout << "||" << vect2 << "||² = " << vect2.norme2() << endl;
	cout << "||" << vect2 << "|| = " << vect2.norme() << endl;
	cout << "Vecteur unitaire de vect1 = (" << ~vect1 << ")" << endl;
 }
 catch (string const& erreur) {
   	cerr << "Erreur : " << erreur << endl;
 }
	
	return 0;
}
