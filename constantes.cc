#include "Vecteur.h"
#include <cmath>
using namespace std;

extern const double precision(1e-10);
extern const double rho_air(1.2);
extern const string erreur_dim("les vecteurs ne sont pas de même dimension.");
extern const string erreur_dim3("les vecteurs ne sont pas de dimension 3.");
extern const string erreur_masse("masse pas valable !");
extern const string erreur_orth("d et g pas orthogonaux");
extern const string erreur_integrateur("pas d`integrateur");
extern const string erreur_objet("pas d`objet");
extern const string erreur_obstacle("pas d`obstacle");
extern const string erreur_tige("tige de longueur nulle");
extern const Vecteur g(0.0, 0.0, -9.81);
extern const double K((M_PI*4)/3);
extern const double alpha(0.8);
extern const double nu(0.01);
extern const double Q(3.77);
