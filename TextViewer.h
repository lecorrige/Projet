#pragma once

#include "SupportADessin.h"

class TextViewer : public SupportADessin
{
public:	
	~SupportADessin() override;
	void dessine(Systeme const& syst) override;
	void dessine(Balle const& ball) override;
};
