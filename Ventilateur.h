#include "Vent.h"
#include "Brique.h"


class Ventilateur : public Compose{
public:
	Ventilateur(Vent const& v, Brique const& b);	
	virtual void agit_sur(ObjetMobile&) override;
};

