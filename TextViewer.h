#pragma once

#include "SupportADessin.h"
#include "Systeme.h"
#include "balle.h"
#include "Pendule.h"
#include <ostream>
#include <iostream>


class TextViewer : public SupportADessin
{
public:	
    TextViewer() =default;
	virtual ~TextViewer() = default;
	 // on ne copie pas les TextViewer
    TextViewer(TextViewer const&)            = delete; 
    TextViewer& operator=(TextViewer const&) = delete;
     // mais on peut les déplacer
    TextViewer(TextViewer&&)            = default; 
    TextViewer& operator=(TextViewer&&) = default;
	
	virtual void dessine(Systeme const&) override;
	virtual void dessine(Balle const&) override;
	virtual void dessine(Pendule const&) override;
    void param(Systeme const&);
	void param(Balle const&);
	void param(Pendule const&);

};

void test_systeme(Systeme& syst, TextViewer& text, int rep);
