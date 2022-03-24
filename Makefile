CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11

CXXFLAGS += -g

all:: testVecteur  testBalle

testVecteur: testVecteur.o Vecteur.o constantes.o
testBalle: testBalle.o balle.o ChampForces.o constantes.o Vecteur.o

testVecteur.o : testVecteur.cc Vecteur.h constantes.h
Vecteur.o : Vecteur.cc Vecteur.h constantes.h
constantes.o : constantes.cc constantes.h Vecteur.h
testBalle.o : testBalle.cc balle.h ChampForces.h constantes.h
balle.o : balle.cc balle.h Vecteur.h 
ChampForces.o : ChampForces.cc ChampForces.h balle.h constantes.h Vecteur.h
