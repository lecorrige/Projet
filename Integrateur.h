#pragma once

#include <iostream>
#include "ObjetMobile.h"
#include "balle.h"
#include "Pendule.h"
using namespace std;


class Integrateur {    
public:
   Integrateur (double dt=0);
   virtual ~Integrateur()                     = default;
   Integrateur(const Integrateur&)            = default;
   Integrateur& operator=(const Integrateur&) = default;
   Integrateur(Integrateur&&)                 = default;
   Integrateur& operator=(Integrateur&&)      = default;
   virtual void evolue(ObjetMobile& obj) const =0;
   double get_dt() const {return dt;}
   virtual Integrateur* copie() const =0;
   virtual std::ostream& affiche_nom(std::ostream&) const =0;
protected:
   double dt;            //pas d'integration        
};



class IntegrateurEulerCromer : public Integrateur {     //ne pas oublier de faire 
public:                                                 //avancer le temps du systeme
   IntegrateurEulerCromer (double dt=0);
   virtual void evolue(ObjetMobile& obj) const override; //regler pb eq dif ordre 1 ou 2
   virtual IntegrateurEulerCromer* copie() const override;
   virtual std::ostream& affiche_nom(std::ostream&) const override;
};

std::ostream& operator<<(std::ostream&, Integrateur const&);
