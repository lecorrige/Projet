#include <iostream>
#include <vector>
#include <string>
#include "Vecteur.h"
#include <cmath>
#include <ostream>
using namespace std;


const string erreur_dim("Les vecteurs ne sont pas de même dimension.");
const string erreur_dim3("Les vecteurs ne sont pas de dimension 3.");
const double precision(1e-10);

Vecteur ::Vecteur (unsigned int n)
: vecteur(n)
{}

Vecteur ::Vecteur (double x, double y, double z) 
{
	vecteur.push_back(x);
	vecteur.push_back(y);
	vecteur.push_back(z);
}
	
Vecteur ::Vecteur (std::initializer_list<double> const& liste) {
	for (auto el : liste) { vecteur.push_back(el); }	
}

bool Vecteur::same_size(Vecteur const& v) const {
	return (v.get_vecteur().size() == vecteur.size());
}

bool operator==(Vecteur const& v1, Vecteur const& v2) {
	 if (not v1.same_size(v2)) {return false;}
     else {
		Vecteur test(v1-v2);
		for (size_t i(0); i<test.get_vecteur().size(); ++i) {
			if (abs(test.get_vecteur()[i]) > precision) {return false;}
		}
	}
	return true;  
}

bool operator!=(Vecteur const& v1, Vecteur const& v2) {return not (v1==v2);}

ostream& operator<<(ostream& sortie, Vecteur const& v) {
	for (auto el : v.get_vecteur()) {sortie << el << " ";}
	return sortie;
}

Vecteur& Vecteur::operator+=(Vecteur const& v) {                   
	if (not this->same_size(v)) {                              
	   throw erreur_dim;
    } else {
		for (size_t i(0); i<vecteur.size(); ++i) {
		   vecteur[i]+= v.get_vecteur()[i];
	    }
	}
    return *this;
}

Vecteur operator+(Vecteur v1, Vecteur const& v2) {
	return v1+=v2;
}

Vecteur& Vecteur::operator-=(Vecteur const& v) {return *this += -v;}

Vecteur operator-(Vecteur const& v) {return -1*v;}

Vecteur operator-(Vecteur v1, Vecteur const& v2) {
	return v1-=v2;
}

double operator*(Vecteur const& v1, Vecteur const& v2) {  //messsage d'erreur envoyé
	double res(0);
	if (not v1.same_size(v2)) {
		throw erreur_dim;
	} else {
	   for (size_t i(0); i<v1.get_vecteur().size(); ++i) {
		   res+=v1.get_vecteur()[i]*v2.get_vecteur()[i];
	   }
    }
	return res;
}

Vecteur Vecteur::operator*=(double k) {
	for (size_t i(0); i<vecteur.size(); ++i) {
		vecteur[i] = k*vecteur[i];
	}
	return *this;
}

Vecteur operator*(Vecteur v1, double k) {return v1*=k;}

Vecteur operator*(double k, Vecteur const& v) {return v*k;}

Vecteur Vecteur::operator^(Vecteur const& v) const {     //message d'erreur envoyé
	Vecteur fin;
	if ((vecteur.size()!=3) or (v.get_vecteur().size()!=3)){
		cerr << "Erreur : " << erreur_dim3 << endl;
	} else {
	    for (int i(0); i<3; ++i) {
		    fin.augmente(vecteur[(i+1)%3]*v.get_vecteur()[(i+2)%3] 
		                 - vecteur[(i+2)%3]*v.get_vecteur()[(i+1)%3]);
	    }
	}
	return fin;
}

double Vecteur::norme2() const {
	double n;
	for (size_t i(0); i<vecteur.size(); ++i){
		n+=vecteur[i]*vecteur[i];
	}
	return n;
}

double Vecteur::norme() const {return sqrt(norme2());}

Vecteur operator~(Vecteur const& v) {return v*(1/v.norme());}

