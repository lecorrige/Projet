#include "SupportADessin.h"

class Dessinable{
public:
	virtual void dessine_sur(SupportADessin& support) =0;
};
