#pragma once

#include "Vecteur.h"



class ObjetMobile
{
protected:
	Vecteur P;
	Vecteur dP;
	Vecteur pos;
    Vecteur vit;
    double R;
    double m_vol;
    Vecteur F;
	
	
public:
    ObjetMobile (double R, double m, Vecteur pos, Vecteur vit, 
                 Vecteur P={0}, Vecteur dP={0}, Vecteur F={0, 0, 0});
	ObjetMobile (double R=0, double m_vol=0, int deg=3); 
	             
    double masse() const;
    void ajoute_force(Vecteur const& df) {F+=df;};
	Vecteur evolution() const;
	void agit_sur(ObjetMobile obj);
	double distance(const ObjetMobile& obj) const;
	
    double get_rayon() const {return R;}     // accesseurs
    double get_masseVol() const {return m_vol;}
    Vecteur get_pos() const {return pos;}
    Vecteur get_vit() const {return vit;}
    Vecteur get_force() const {return F;}
    Vecteur get_P() const {return P;}
    Vecteur get_dP() const {return dP;}
    void set_f(Vecteur force) {F+=force;}
};

std::ostream& operator<<(std::ostream& sortie,  ObjetMobile const& obj) ;
