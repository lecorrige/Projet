#include "Obstacles.h"
#include "Vecteur.h"
#include "ObjetMobile.h"

class Plan : public Obstacle {
private:
	Vecteur n;
	
	virtual Vecteur normale(const ObjetMobile&) const override {return n;}
public:
	Plan(Vecteur pos=(3), Vecteur n=(3));

	virtual Vecteur point_plus_proche(const ObjetMobile&) const override;
	virtual std::ostream& affiche(std::ostream&) const override;
	virtual Plan* copie() const override;
	Vecteur get_n() const {return n;}
};
