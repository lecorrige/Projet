class Obstacle
{
protected:
	Vecteur pos;

public:
	 double distance(const ObjetMobile& obj) const;
	 
	 void agit_sur(ObjetMobile obj) const;
	 
	 Vecteur point_plus_proche(const ObjetMobile& obj) const;

};
