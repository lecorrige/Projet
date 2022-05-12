#pragma once

#include <iostream>
#include "Integrateur.h"
#include "ObjetMobile.h"


class IntegrateurNewmark : public Integrateur {
public:
	IntegrateurNewmark (double e, double dt=0);
	virtual void evolue(ObjetMobile& obj) const override;
	virtual IntegrateurNewmark* copie() const override;
    virtual std::ostream& affiche_nom(std::ostream&) const override;
private:
	double epsilon;
};
