#include <iostream>
#include "Integrateur.h"
#include "ObjetMobile.h"
#include "balle.h"
using namespace std;


Integrateur::Integrateur (double dt) 
: dt(dt)
{}

IntegrateurEulerCromer::IntegrateurEulerCromer (double dt) 
: Integrateur(dt)
{}


void IntegrateurEulerCromer::evolue(ObjetMobile& obj) const { 
   obj.set_dP(obj.get_dP() + dt*obj.evolution());                      //regler pb eq dif ordre 1 ou 2
   obj.set_P(obj.get_P() + dt*obj.get_dP()); 
}

