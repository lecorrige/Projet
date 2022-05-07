#include "TextViewer.h"
#include <iostream>
using namespace std;


void TextViewer::dessine(Systeme const& syst) {
	for (size_t i(0); i<syst.objets_size(); ++i) {
		syst.get_obj(i).dessine_sur(*this);
	}
	if (syst.objets_size() > 1) {
		cout << syst.get_obj(0).distance(syst.get_obj(1));   //complement
	}
}

void TextViewer::param(Systeme const& syst) {
	cout << "Dans l`ordre : " << endl;
	for (size_t i(0); i<syst.objets_size(); ++i) {syst.get_obj(i).param_sur(*this);}
	cout << "##  distance entre objet1 et objet2" << endl;   //complememt
}

void TextViewer::param(Balle const& b) {
   cout << "    Balle" << endl;
   cout << "##  Position de la balle "<<endl;
   cout << "##  Vitesse de la balle " << endl; 
}

void TextViewer::param(Pendule const& p) {
	cout <<"    Pendule" << endl;
	cout <<"##  Theta"<<endl;
	cout <<"##  Theta point"<<endl;
	cout <<"##  f()"<<endl;
	cout <<"##  Position bout du pendule"<<endl;
}

void TextViewer::dessine(Balle const& ball) {
     cout <<ball.pos()
		  <<ball.vit();	
}

void TextViewer::dessine(Pendule const& pend) {
	cout <<pend.get_P()
		 <<pend.get_dP()
	     <<pend.evolution()
         <<pend.pos_masse();
}

void test_systeme(Systeme& syst, TextViewer& text, int rep) {
	text.param(syst);
	cout << endl;
	for (int i(0); i<rep; ++i){
		syst.dessine_sur(text);
		syst.evolue();
		cout << endl;
	}
}

