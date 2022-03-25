#pragma once

#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"

class Balle : public ObjetMobile {
public:
	using ObjetMobile::ObjetMobile;     //attention si nouveaux attributs
	Vecteur get_pos() const { return pos; }  
	Vecteur get_vit() const { return vit; }
	
	void set_pos(Vecteur p) { pos=p; }
	void set_vit(Vecteur v) { vit=v; }

};

//rajouter operateur affichage
