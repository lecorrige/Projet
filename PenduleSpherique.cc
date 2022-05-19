#include "constantes.h"
#include "PenduleSpherique.h"
#include <cmath>

PenduleSpherique::PenduleSpherique(double R, double m_vol, double L, double b,
								   Vecteur P, Vecteur dP, Vecteur d, Vecteur O)
:Pendule(R,m_vol,L,b,P,dP,d,O)
{ F=g; }


double ur(){
	return sin(t1())*cos(t2())*d+sin(t1())*sin(t2())*d^(~g)+cos(t1())(~g);
}

double ut(){
	return cos(t1())*cos(t2())*d+cos(t1())*sin(t2())*d^(~g)-sin(t1())(~g);
}

double up(){
	return -sin(t2())*d+cos(t2())*d^(~g);
}

Vecteur PenduleSpherique::evolution() const { 
	return { sin(t1())*(cos(t1())*dt2()*dt2()-F/L),
				-2*1/tan(t1())*dt1()*dt2()		    } ;
}

Vecteur PenduleSpherique::pos_masse() const {
	return O+L*cos(t1())*(~g)+L*sin(t1())*cos(t2())*d+L*sin(t1())*sin(t2())*d^(~g);
}

Vecteur PenduleSpherique::vit_masse() const {
	return L*(-dt1()*sin(t1())*(~g)+(dt1()*cos(t1())*cos(t2())-dt2()*sin(t1())*sin(t2()))*d
			  +(dt1()*cos(t1())*sin(t2())-dt2()*sin(t1())*cos(t2()))*d^(~g));
}

Vecteur PenduleSpherique::force_masse() const {
	return masse()*L*((-dt1()*dt1()-dt2()*dt2()*sin(t1())*sin(t1()))*ur()
		   +(evolution().get_vecteur[0]-dt2()*dt2()*sin(t1())*sin(t1()))*ut
		   +(evolution().get_vecteur[1]*sin(t1())-2*dt1()*dt2()*cos(t1()))*up);
}
