#pragma once

#include "ObjetMobile.h"
#include "Pendule.h"
#include "Vecteur.h"

class PenduleSpherique : public Pendule {
public:	
	PenduleSpherique(double R, double m_vol, double L, double b, Vecteur P, 
					 Vecteur dP, Vecteur d={0, 1, 0}, Vecteur O=(3));
	virtual Vecteur evolution() const override;
	virtual void ajoute_vit(Vecteur const& v) override {dP+=(v*d)*d;} 
	virtual ObjetMobile* copie() const override;	
	virtual void ajoute_force(Vecteur const& df) override;
	virtual Vecteur pos_masse() const override;
	virtual Vecteur vit_masse() const override;
	virtual Vecteur force_masse() const override;
	double t1() const { return P.get_vecteur()[0]; }
	double t2() const { return P.get_vecteur()[1]; }
	double dt1() const { return dP.get_vecteur()[0]; }
	double dt2() const { return dP.get_vecteur()[1]; }
	Vecteur ur() const;
	Vecteur ut() const;
	Vecteur up() const;
};
