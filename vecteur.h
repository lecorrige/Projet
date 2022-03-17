#pragma once

#include <iostream>
#include <vector>

typedef std::vector<double> Vector;

class Vecteur {
public:

    Vecteur() = default;
    Vecteur (Vector v);

	void augmente(double valeur) {vecteur.push_back(valeur);}
	void set_coord(int pos, double valeur) {vecteur[pos] = valeur;}
	void affiche() const; 
	bool compare(Vecteur const& v, double precision=1e-10) const;
	Vector get_vecteur() const;
	Vecteur addition(Vecteur const& v) const;
	Vecteur mult(double k) const;
	Vecteur oppose() const;
	Vecteur soustraction(Vecteur const& v) const;
	double prod_scal(Vecteur const& v) const;
	Vecteur prod_vect(Vecteur const& v) const;
	double norme() const;
	double norme2() const;
	Vecteur unitaire() const;
	void test_add(Vecteur const& v1) const;
	
private:
	Vector vecteur;
	bool same_size(Vecteur const& v) const;
	size_t min_size(Vecteur const& v) const;
	size_t max_size(Vecteur const& v) const;
};
