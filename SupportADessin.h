#pragma once

#include "Systeme.h"
#include "balle.h"
#include "Pendule.h"
#include "Plan.h"
#include "Brique.h"


class SupportADessin
{
public:
	virtual ~SupportADessin() = default;
	// on suppose ici que les supports ne seront ni copiés ni déplacés
	
	virtual void dessine(Systeme const& syst) = 0;
	virtual void dessine(Balle const& ball) = 0;
	virtual void dessine(Pendule const& pend) =0;
	virtual void dessine(Plan const& plan) =0;
	virtual void dessine(Brique const& brique) =0;
	// ... autres choses que vous voudriez dessiner...
};
