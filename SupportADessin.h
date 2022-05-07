#pragma once

class Systeme;
class Balle;
class Pendule;
class Plan;
class Brique;

class SupportADessin
{
public:
	virtual ~SupportADessin() = default;
	//on ne copie pas les Supports
	SupportADessin(SupportADessin const&)            = delete; 
    SupportADessin& operator=(SupportADessin const&) = delete;
    // mais on peut les déplacer
    SupportADessin(SupportADessin&&)            = default; 
    SupportADessin& operator=(SupportADessin&&) = default;
    SupportADessin() = default; 
	
	virtual void dessine(Systeme const&) = 0;
	virtual void dessine(Balle const&) = 0;
	virtual void dessine(Pendule const&) =0;
	// ... autres choses que vous voudriez dessiner...
	virtual void param(Systeme const&) =0;
	virtual void param(Balle const&) = 0;
	virtual void param(Pendule const&) =0;
};
