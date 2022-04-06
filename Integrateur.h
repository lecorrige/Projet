#pragma once

#include <iostream>
#include "ObjetMobile.h"
#include "balle.h"
#include "Pendule.h"
using namespace std;


class Integrateur {       //à expliquer plus tard
public:
   Integrateur (double dt=0);
   virtual void evolue(ObjetMobile& obj) const =0;
   double get_dt() const {return dt;}
protected:
   double dt;            //pas d'integration        
};



class IntegrateurEulerCromer : public Integrateur {     //ne pas oublier de faire 
public:                                                 //avancer le temps du systeme
   IntegrateurEulerCromer (double dt=0);
   virtual void evolue(ObjetMobile& obj) const override;                  //regler pb eq dif ordre 1 ou 2
};
