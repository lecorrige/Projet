#include "Simple.h"
#include "Dessinable.h"
#include "Systeme"
#include <vector>
#include <memory>



class Compose : public Objet, public Dessinable {
public:
	Compose(std::vector<Objet*>=0);
	virtual void ajoute_a(Systeme) const override;
	
protected:
	std::vector<std::unique_ptr<Objet>> objets;
};

