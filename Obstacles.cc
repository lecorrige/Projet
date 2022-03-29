#include "Obstacle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include <iostream>
using namespace std;


Obstacle::Obstacle(Vecteur pos)
:pos(pos)
{}

double Obstacle::distance(const ObjetMobile& obj) const{
	return (pos-point_plus_proche(obj)).norme()-obj.get_rayon();
}
 
void Obstacle::agit_sur(ObjetMobile obj) const{
	cout<<"plus tard"<<endl;
}
