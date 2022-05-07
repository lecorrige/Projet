#pragma once

#include "SupportADessin.h"

class Dessinable{
public:
	virtual ~Dessinable()=default;
	Dessinable()                             = default;
	Dessinable(Dessinable const&)            = default;
    Dessinable& operator=(Dessinable const&) = default;
    Dessinable(Dessinable&&)                 = default; 
    Dessinable& operator=(Dessinable&&)      = default;
	
	virtual void dessine_sur(SupportADessin&) =0;
	virtual void param_sur(SupportADessin&) =0;
};
