#include <iostream>
#include <vector>
#include <string>
#include "Vecteur.h"
#include <cmath>
using namespace std;


const string erreur_dim("Les vecteurs ne sont pas de même dimension.");
const string erreur_dim3("Les vecteurs ne sont pas de dimension 3.");

Vecteur::Vecteur(Vector v): vecteur(v) {}

Vector Vecteur::get_vecteur() const {return vecteur;}

bool Vecteur::compare(Vecteur const& v, double precision) const {
		if (v.get_vecteur().size() != vecteur.size()) {return false;}
		else {
			for (size_t i(0); i<vecteur.size(); ++i) {
				if (v.get_vecteur()[i]-vecteur[i] >= precision) {return false;}
			}
		}
		return true;
	}
	
void Vecteur::affiche() const {
	for (auto el : vecteur) {cout << el << " ";} 
}

bool Vecteur::same_size(Vecteur const& v) const {
	return (v.get_vecteur().size() == vecteur.size());
}

size_t Vecteur::min_size(Vecteur const& v) const {    //pas utile
	if (vecteur.size()<v.get_vecteur().size()) {return vecteur.size();}
	else { return v.get_vecteur().size();}
}

size_t Vecteur::max_size(Vecteur const& v) const {     //pas utile
	if (vecteur.size()<v.get_vecteur().size()) {return v.get_vecteur().size();}
	else { return vecteur.size();}
}

Vecteur operator+(Vecteur v1, Vecteur const& v2) {       //penser à attraper 
														 //le message d'erreur       
	if (not v1.same_size(v2)) {
	   throw erreur_dim;
    } else {
		v1+=v2;
	}	
    return v1;
}

Vecteur operator-(Vecteur const& v) {
	return -1*v;
}

Vecteur operator-(Vecteur v1, Vecteur const& v2) {
	v1 -= v2;
	return v1;
}

double operator*(Vecteur v1,Vecteur const& v2) {
	return v1*=v2;
}

Vecteur Vecteur::operator*(double k) const {
	Vecteur fin;
	for (size_t i(0); i<vecteur.size(); ++i) {
		fin.augmente(k*vecteur[i]);
	}
	return fin;
}


Vecteur Vecteur::operator^(Vecteur const& v) const {
	Vecteur fin;
	if ((vecteur.size()!=3) or (v.get_vecteur().size()!=3)){
		throw erreur_dim3;
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

double Vecteur::norme() const {
	return sqrt(norme2());
}

Vecteur operator~(Vecteur const& v) {
	return v*1/norme();
}



Vecteur Vecteur::operator+=(Vecteur const& v) const {       //penser à attraper 
													  //le message d'erreur       
	for (size_t i(0); i<vecteur.size(); ++i) {
		vecteur[i]+=v.get_vecteur()[i];
	}
    return vecteur;
}

Vecteur Vecteur::operator-=(Vecteur const& v) const {
	return vecteur += -v;
}

double Vecteur::operator*=(Vecteur const& v) const {
	double res;
	if (not same_size(v)) {
		throw erreur_dim;
	} else {
	   for (size_t i(0); i<min_size(v); ++i) {
		   res+=vecteur[i]*v.get_vecteur()[i];
	   }
    }
	return res;
}
