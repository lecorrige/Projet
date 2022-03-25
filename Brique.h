class Brique : public Obstacle
{
private:
	Vecteur L;
	Vecteur l;
	double h;

public:
	Brique (Vecteur pos, Vecteur longueur, Vecteur largeur, double h);
	
	Vecteur proche_plan_fini(const ObjetMobile& obj) const;
	
	Vecteur point_plus_proche(const ObjetMobile& obj) const;
};
