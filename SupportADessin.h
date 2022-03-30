#pragma once

#include "Systeme.h"
#include "Balle.h"


class SupportADessin
{
public:
	virtual ~SupportADessin() = default;
	// on suppose ici que les supports ne seront ni copiés ni déplacés
	
	virtual void dessine(Systeme const& syst) = 0;
	virtual void dessine(Balle const& ball) = 0;
	// ... autres choses que vous voudriez dessiner...
};
