#pragma once

#include <iostream>
#include <vector>

typedef std::vector<double> Vector;

class Vecteur {
public:

    Vecteur (unsigned int n) 
    : vecteur(n)
    {}
    Vecteur (double x, double y, double z) 
    {
		Vecteur v;
		v.augmente(x);
		v.augmente(y);
		v.augmente(z);
	}
	Vecteur (initializer_list <double> const& liste) {
		for (auto el : liste) { vecteur.push_back(el); }	
	}

	void augmente(double valeur) {vecteur.push_back(valeur);}
	void set_coord(int pos, double valeur) {vecteur[pos] = valeur;}
	void affiche() const; 
	bool compare(Vecteur const& v, double precision=1e-10) const;
	Vector get_vecteur() const;
	Vecteur operator+=(Vecteur const& v) const;
	Vecteur operator-=(Vecteur const& v) const;
	Vecteur operator*=(Vecteur const& v) const;
	Vecteur operator*=(double k) const;
	Vecteur operator^(Vecteur const& v) const;
	double norme() const;
	double norme2() const;
	void test_add(Vecteur const& v1) const;
	
private:
	Vector vecteur;
	bool same_size(Vecteur const& v) const;
	size_t min_size(Vecteur const& v) const;
	size_t max_size(Vecteur const& v) const;
};


Vecteur operator+(Vecteur v1, Vecteur const& v2) ;
Vecteur operator*(double k) ;
Vecteur operator-(Vecteur v1, Vecteur const& v2) ;
double operator*(Vecteur v1, Vecteur const& v2) ;
Vecteur operator-(Vecteur const& v) ;
Vecteur operator~(Vecteur const &v) ;Vecteur operator~(Vecteur const &v) ;
