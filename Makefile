CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11

CXXFLAGS += -g

all:: testVecteur  testBalle  testIntegrateur1  testIntegrateur2  testPendule  testObstacle testSysteme test1exP9A test2exP9A  testChocs 

testVecteur: testVecteur.o Vecteur.o constantes.o
testBalle: testBalle.o ChampForces.o ObjetMobile.o balle.o ChampForces.o constantes.o Vecteur.o
testIntegrateur1: testIntegrateur1.o constantes.o  ChampForces.o balle.o Vecteur.o ObjetMobile.o Integrateur.o
testIntegrateur2: testIntegrateur2.o constantes.o ChampForces.o balle.o Vecteur.o ObjetMobile.o Integrateur.o
testPendule: testPendule.o constantes.o ChampForces.o Pendule.o Vecteur.o ObjetMobile.o Integrateur.o
testObstacle: testObstacle.o constantes.o ChampForces.o Vecteur.o ObjetMobile.o balle.o Obstacles.o Plan.o Brique.o
testSysteme: testSysteme.o Systeme.o ObjetMobile.o balle.o Pendule.o Obstacles.o Brique.o Plan.o Integrateur.o ChampForces.o constantes.o Vecteur.o Dessinable.o TextViewer.o
test1exP9A: test1exP9A.o Systeme.o ObjetMobile.o balle.o Pendule.o Obstacles.o Brique.o Plan.o Integrateur.o ChampForces.o constantes.o Vecteur.o Dessinable.o TextViewer.o
test2exP9A: test2exP9A.o Systeme.o ObjetMobile.o balle.o Pendule.o Obstacles.o Brique.o Plan.o Integrateur.o ChampForces.o constantes.o Vecteur.o Dessinable.o TextViewer.o
testChocs: testChocs.o balle.o Plan.o ChampForces.o constantes.o Vecteur.o ObjetMobile.o Obstacles.o Pendule.o Systeme.o Integrateur.o TextViewer.o

testVecteur.o : testVecteur.cc Vecteur.h constantes.h
Vecteur.o : Vecteur.cc Vecteur.h constantes.h
constantes.o : constantes.cc constantes.h Vecteur.h
ChampForces.o : ChampForces.cc ChampForces.h ObjetMobile.h constantes.h Vecteur.h

ObjetMobile.o : ObjetMobile.cc ObjetMobile.h Vecteur.h constantes.h Dessinable.h
Pendule.o : Pendule.cc Pendule.h Vecteur.h constantes.h ObjetMobile.h
balle.o : balle.cc balle.h Vecteur.h ObjetMobile.h constantes.h
testBalle.o : testBalle.cc balle.h ChampForces.h constantes.h ObjetMobile.h

Integrateur.o : Integrateur.cc Integrateur.h ObjetMobile.h 
testIntegrateur1.o : testIntegrateur1.cc Integrateur.h Vecteur.h balle.h ChampForces.h constantes.h ObjetMobile.h
testIntegrateur2.o : testIntegrateur2.cc Integrateur.h Vecteur.h balle.h ChampForces.h constantes.h ObjetMobile.h
testPendule.o: testPendule.cc ChampForces.h Pendule.h constantes.h Integrateur.h Vecteur.h

Obstacles.o: Obstacles.cc Obstacles.h Vecteur.h ObjetMobile.h Dessinable.h
Brique.o: Brique.cc Brique.h Vecteur.h Obstacles.h constantes.h
Plan.o: Plan.cc Plan.h Obstacles.h Vecteur.h ObjetMobile.h
testObstacle.o: testObstacle.cc Obstacles.h balle.h Plan.h Brique.h ObjetMobile.h ChampForces.h

testSysteme.o: testSysteme.cc Systeme.h ObjetMobile.h balle.h Pendule.h Obstacles.h Plan.h Brique.h ChampForces.h Dessinable.h SupportADessin.h
Systeme.o: Systeme.cc Systeme.h ObjetMobile.h Integrateur.h Obstacles.h ChampForces.h constantes.h Dessinable.h TextViewer.h
Dessinable.o: Dessinable.h SupportADessin.h 
test1exP9A.o: test1exP9A.cc Systeme.h ObjetMobile.h balle.h Pendule.h Obstacles.h Plan.h Brique.h ChampForces.h
test2exP9A.o: test2exP9A.cc Systeme.h ObjetMobile.h balle.h Pendule.h Obstacles.h Plan.h Brique.h ChampForces.h
TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h Systeme.h balle.h Pendule.h
testChocs.o: testChocs.cc balle.h ChampForces.h Plan.h constantes.h
