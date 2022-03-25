#include "Vecteur.h"
#include <cmath>
using namespace std;

extern const double precision(1e-10);
extern const double rho_air(1.2);
extern const string erreur_dim("Les vecteurs ne sont pas de même dimension.");
extern const string erreur_dim3("Les vecteurs ne sont pas de dimension 3.");
extern const Vecteur g(0.0, 0.0, -9.81);
extern const double K((M_PI*4)/3);
