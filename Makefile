CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11

CXXFLAGS += -g

all:: testVecteur  testBalle  testIntegrateur1  testIntegrateur2  testPendule

testVecteur: testVecteur.o Vecteur.o constantes.o
testBalle: testBalle.o ChampForces.o ObjetMobile.o balle.o ChampForces.o constantes.o Vecteur.o
testIntegrateur1: testIntegrateur1.o constantes.o ChampForces.o balle.o Vecteur.o ObjetMobile.o Integrateur.o
testIntegrateur2: testIntegrateur2.o constantes.o ChampForces.o balle.o Vecteur.o ObjetMobile.o Integrateur.o
testPendule: testPendule.o constantes.o ChampForces.o Pendule.o Vecteur.o ObjetMobile.o Integrateur.o

testVecteur.o : testVecteur.cc Vecteur.h constantes.h
Vecteur.o : Vecteur.cc Vecteur.h constantes.h
constantes.o : constantes.cc constantes.h Vecteur.h
ChampForces.o : ChampForces.cc ChampForces.h ObjetMobile.h constantes.h Vecteur.h

ObjetMobile.o : ObjetMobile.cc ObjetMobile.h Vecteur.h constantes.h
Pendule.o : Pendule.cc Pendule.h Vecteur.h constantes.h ObjetMobile.h
balle.o : balle.cc balle.h Vecteur.h ObjetMobile.h constantes.h
testBalle.o : testBalle.cc balle.h ChampForces.h constantes.h ObjetMobile.h

Integrateur.o : Integrateur.cc Integrateur.h ObjetMobile.h 
testIntegrateur1.o : testIntegrateur1.cc Integrateur.h Vecteur.h balle.h ChampForces.h constantes.h ObjetMobile.h
testIntegrateur2.o : testIntegrateur2.cc Integrateur.h Vecteur.h balle.h ChampForces.h constantes.h ObjetMobile.h
testPendule.o: testPendule.cc ChampForces.h Pendule.h constantes.h Integrateur.h Vecteur.h
