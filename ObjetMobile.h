#pragma once

#include "Vecteur.h"
#include "Dessinable.h"
#include "constantes.h"


class ObjetMobile : public Dessinable {
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
	ObjetMobile (double R=0, double m_vol=0, double b=0, int deg=3); 
	             
    double masse() const;
    virtual void ajoute_force(Vecteur const& df) {F+=df;}
	virtual Vecteur evolution() const =0;
	void agit_sur(ObjetMobile& obj, bool =false);
	double distance(const ObjetMobile& obj) const;
	void test_size() const;       //pour tester si P et dP sont bien de la meme taille 
	
	virtual std::ostream& affiche(std::ostream& sortie) const;
	
    double get_rayon() const {return R;}     // accesseurs
    double get_masseVol() const {return m_vol;}
    double get_b() const {return b;}
    Vecteur get_P() const {return P;}
    Vecteur get_dP() const {return dP;}
    Vecteur get_F() const {return F;}
    void set_pos(Vecteur const& p) {P=p;}
    void set_vit(Vecteur const& dp) {dP=dp;}
    void set_F(Vecteur const& f) {F=f;}
    
    virtual Vecteur pos() const {return P;} //renvoie pos de 
									        //chacune des sous-classes
	virtual Vecteur vit() const {return dP;} //renvoie vit de 
									         //chacune des sous-classes		
	virtual void ajoute_vit(Vecteur const& v) =0;
	virtual ObjetMobile* copie() const =0;	
	void test_choc(ObjetMobile&);	
};

std::ostream& operator<<(std::ostream& sortie,  ObjetMobile const& obj);
