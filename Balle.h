#pragma once

#include <iostream>
#include <vector>
#include "Vecteur.h"

class Balle : public ObjetMobile
{
public:
	Balle (double R, double m_vol, Vecteur P, Vecteur dP, Vecteur pos, Vecteur vit, Vecteur F, int deg=3);
	
	Vecteur get_pos() const { return pos; }  
	Vecteur get_vit() const { return vit; }
	
	void set_pos(Vecteur pos) { pos=p; }
	void set_vit(Vecteur vit) { vit=v; }

};
