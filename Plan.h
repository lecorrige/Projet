
class Plan : public Obstacle
{
private:
	Vecteur n;
public:
	Plan(Vecteur O, Vecteur n);

	Vecteur point_plus_proche(const ObjetMobile& obj) const;
};
