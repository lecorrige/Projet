#pragma once

#include <iostream>
#include "ObjetMobile.h"


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

std::ostream& operator<<(std::ostream&, Integrateur const&);

