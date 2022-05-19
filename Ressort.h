#pragma once
#include "Vecteur.h"
#include "ObjetMobile.h"


class Ressort : public ObjetMobile{
public:
	Ressort(double R, double m_vol, Vecteur P, Vecteur dP, 
			double k, Vecteur d, double b=0);
	virtual Vecteur evolution() const override;
	virtual void ajoute_vit(Vecteur const& v) override {dP+=(v*d)*d;} 
	virtual ObjetMobile* copie() const override;	
	virtual void ajoute_force(Vecteur const& df) override;
	virtual Vecteur pos() const override;
	virtual Vecteur vit() const override;
private:
	double k;
	Vecteur d;
	Vecteur O;
};
	
