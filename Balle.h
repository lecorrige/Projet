#pragma once

#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"

class Balle : public ObjetMobile {
public:
	using ObjetMobile::ObjetMobile;     //attention si nouveaux attributs
	
	Vecteur evolution() const; 
	virtual void ajoute_vit(Vecteur const& v) override {dP+=v;}	
	virtual std::ostream& affiche(std::ostream& sortie) const override;
	virtual Balle* copie() const override;
	virtual void dessine_sur(SupportADessin& support)override {support.dessine(*this);}	
	virtual void param_sur(SupportADessin& support) override {support.param(*this);}
};

