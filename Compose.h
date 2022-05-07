#include "Compose.h"

Compose::Compose(std::vector<Objet*> obj){
	for (auto el : obj){ objets.push_back(unique_ptr<Objet>(el)); }
}

void Compose::ajoute_a(Systeme s) const{
	for (auto const& el:objets){
		el->ajoute_a(s);
	}
}
