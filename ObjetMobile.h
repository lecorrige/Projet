#pragma once

#include "Vecteur.h"
#include "constantes.h"


class ObjetMobile {
protected:
    double R;
    double m_vol;
    double b;       //frottement (viscosité de l'air et/ou frottement fluide)
    Vecteur P;
	Vecteur dP;
    Vecteur F;
    
    void test_masse() const;
	
	
public:
    ObjetMobile (double R, double m_vol, Vecteur P, Vecteur dP, double b=0);
    ObjetMobile (Vecteur P, Vecteur dP);
	ObjetMobile (double R=0, double m_vol=0, double b=0, int deg=3); 
	             
    double masse() const;
    void ajoute_force(Vecteur const& df) {F+=df;};
	virtual Vecteur evolution() const =0;
	void agit_sur(ObjetMobile& obj);
	double distance(const ObjetMobile& obj) const;
	void test_size() const;       //pour tester si P et dP sont bien de la meme taille 
	
	virtual ostream& affiche(ostream& sortie) const;
	
    double get_rayon() const {return R;}     // accesseurs
    double get_masseVol() const {return m_vol;}
    double get_b() const {return b;}
    Vecteur get_force() const {return F;}
    Vecteur get_P() const {return P;}
    Vecteur get_dP() const {return dP;}
    Vecteur get_F() const {return F;}
    void set_P(Vecteur const& p) {P=p;}
    void set_dP(Vecteur const& dp) {dP=dp;} 
    void set_F(Vecteur const& f) {F=f;}
    
    virtual Vecteur pos() const =0; //definie dans les sous-classes, renvoie pos de 
									//chacune des sous-classes
	virtual Vecteur vit() const =0; //definie dans les sous-classes, renvoie vit de 
									//chacune des sous-classes		
	virtual void ajoute_vit(Vecteur v) const =0;				
};

std::ostream& operator<<(std::ostream& sortie,  ObjetMobile const& obj);
