#pragma once

#include "Integrateur.h"
#include "ObjetMobile.h"
#include <iostream>

class IntegrateurEulerCromer : public Integrateur {     //ne pas oublier de faire 
public:                                                 //avancer le temps du systeme
   IntegrateurEulerCromer (double dt=0);
   virtual void evolue(ObjetMobile& obj) const override; //regler pb eq dif ordre 1 ou 2
   virtual IntegrateurEulerCromer* copie() const override;
   virtual std::ostream& affiche_nom(std::ostream&) const override;
};
