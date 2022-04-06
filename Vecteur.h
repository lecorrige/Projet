#pragma once

#include <vector>
#include <ostream>

typedef std::vector<double> Vector;

class Vecteur {
public:
    Vecteur (unsigned int n=0); 
    Vecteur (double x, double y, double z);
	Vecteur (std::initializer_list<double> const& liste);

	void augmente(double valeur) {vecteur.push_back(valeur);}
	void set_coord(int pos, double valeur) {vecteur[pos] = valeur;}
	Vector get_vecteur() const {return vecteur;}
	Vecteur& operator+=(Vecteur const& v);
	Vecteur& operator-=(Vecteur const& v);
	Vecteur operator*=(double k);
	Vecteur operator^(Vecteur const& v) const;
	double norme() const;
	double norme2() const;
	bool same_size(Vecteur const& v) const;
	
private:
	Vector vecteur;
	size_t min_size(Vecteur const& v) const;
	size_t max_size(Vecteur const& v) const;
};

std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);
Vecteur operator+(Vecteur v1, Vecteur const& v2);
Vecteur operator-(Vecteur v1, Vecteur const& v2);
double operator*(Vecteur const& v1, Vecteur const& v2);
Vecteur operator*(Vecteur v1, double k);
Vecteur operator/(Vecteur v1, double k);
Vecteur operator*(double k, Vecteur const& v);
Vecteur operator-(Vecteur const& v);
Vecteur operator~(Vecteur const& v);
bool operator==(Vecteur const& v1, Vecteur const& v2);
bool operator!=(Vecteur const& v1, Vecteur const& v2);
