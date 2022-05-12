#pragma once

#include <iostream>
#include "Integrateur.h"
#include "ObjetMobile.h"


class IntegrateurRunge : public Integrateur {
public:
	IntegrateurRunge (double dt=0);
	virtual void evolue(ObjetMobile& obj) const override;
	virtual IntegrateurRunge* copie() const override;
    virtual std::ostream& affiche_nom(std::ostream&) const override;
};
