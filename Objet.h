#include "Systeme.h"
#include "ObjetMobile.h"

class Objet {
public:
	virtual void ajoute_a(Systeme s) const=0;	
	virtual void agit_sur(ObjetMobile&)=0;
};

