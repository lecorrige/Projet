#include "Objet.h"
#include "Systeme.h"

class Simple : public Objet{
	virtual void ajoute_a(Systeme) const override { s.ajouter(*this); }
};
