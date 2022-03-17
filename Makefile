CC=g++

all: testVecteur

testVecteur: testVecteur.o Vecteur.o

testVecteur.o : testVecteur.cc Vecteur.h
Vecteur.o : Vecteur.cc Vecteur.h
