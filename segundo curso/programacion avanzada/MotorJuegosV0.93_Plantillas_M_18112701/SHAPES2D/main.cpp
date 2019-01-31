#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>
#include "vector3d.h"
#include "solido.h"
#include "cubo.h"
#include "esfera.h"
#include "cilindro.h"
#include "escena.h"
#include "camara.h"
#include "pared.h"
#include "rosco.h"
#include "compuesto.h"
#include "modelo.h"

using namespace std;

int mx = -1;
int my = -1;
double t = 0;
double dt = 0.1;

CamaraTPS cam;
Modelo* minion;

Escena e;

void displayMe(void) {
	/* Borrar pantalla*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* Inicializar transformaciones*/
	glLoadIdentity();

	/* Camara */
	cam.render();

	/* Luces */
	GLfloat lightpos[] = { 5.0,15.0,5.0,0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	/* Visualiza escena */
	e.render();

	/* Mostrar Buffer*/
	glutSwapBuffers();
}
void mouseMoved(int x, int y)
{
	if (mx >= 0 && my >= 0) {
		//pitch += y - my;
		//yaw += x - mx;
		Vector3D r;
		r = cam.getRot() + Vector3D(y - my, x - mx, 0);
		cam.setRot(r);
	}
	mx = x;
	my = y;
	glutPostRedisplay();
}
void mousePress(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mx = x;
		my = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mx = -1;
		my = -1;
	}
}
void keyPressed(unsigned char key, int px, int py) {
	Vector3D vp;
	Solido* s;
	double x;
	switch (key) {
	case 'z':
	case 'Z':
		//roll++;
		break;
	case 'x':
	case 'X':
		//roll--;
		break;
	case 't':
	case 'T':
		cam.update(dt * 2);
		break;
	case 'g':
	case 'G':
		cam.update(-dt * 2);
		break;
	case 'u':
	case 'U':
		cam.updateLateral(dt * 2);
		break;
	case 'I':
	case 'i':
		cam.updateLateral(-dt * 2);
		break;
	case 'p':
	case 'P':
		s = cam.getSolido();
		s->setRot(s->getRot() + Vector3D(0, 1, 0));
		cout << "s->getRot()=" << s->getRot() << endl;
		cam.update(dt);
		break;
	case 'o':
	case 'O':
		s = cam.getSolido();
		s->setRot(s->getRot() - Vector3D(0, 1, 0));
		cout << "s->getRot()=" << s->getRot() << endl;
		cam.update(dt);
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay(); //request display() call ASAP
}

double getRand(double max, double min = 0) {
	double n = max - min;
	int ir = rand() % 1000;
	return min + (double)ir / 1000 * n;
}
void init(void) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	cam.setPos(Vector3D(0, 1.65, 10));

	Cubo *c;
	Esfera *f;
	Pared *p;
	Vector3D v;
	Rosco* r;
	Cilindro* cl;

	minion = new Modelo("minion.obj");
	e.add(minion);
	cam.setSolido(minion);
	Compuesto* arbol = new Compuesto();
	f = new Esfera();
	f->setPos(Vector3D(0, 4.5, 0));
	f->setCol(Vector3D(0, 1, 0));
	f->setR(2);
	arbol->add(f);
	cl = new Cilindro(0.5, 4);
	cl->setPos(Vector3D(0, 4, 0));
	cl->setCol(Vector3D(1, 0.25, 0));
	arbol->add(cl);
	e.add(arbol);
	Compuesto* arbol0;
	for (int i = 0; i < 50; i++) {
		arbol0 = arbol->clone();
		arbol0->setPos(Vector3D(getRand(45, -45), 0, getRand(45, -45)));
		e.add(arbol0);
	}
	f->setR(4);
	r = new Rosco();
	r->setCol(Vector3D(getRand(1), getRand(1), getRand(1)));
	r->setVel(Vector3D(0, 0, -0.1));
	e.add(r);
	c = new Cubo();
	c->setPos(Vector3D(0.6, 1, 0));
	c->setVel(Vector3D(0.7, 0, -0.71));
	c->setCol(Vector3D(1, 0, 0));
	c->setF(Vector3D(0, -0.98, 0));
	c->setM(1);
	c->setS(0.4);
	//cout << *c << endl;
	e.add(c);
	f = new Esfera();
	f->setPos(Vector3D(-0.4, 1.2, 0));
	f->setVel(Vector3D(-0.3, 0, 0.7));
	f->setCol(Vector3D(1, 0, 1));
	f->setF(Vector3D(0, -0.98, 0));
	f->setM(1);
	f->setR(0.4);
	e.add(f);
	p = new Pared(10);
	p->setPos(Vector3D(0, 0, -2));
	e.add(p);
	p = new Pared(10);
	p->setPos(Vector3D(0, 0, 2));
	e.add(p);
	p = new Pared(100);
	p->setPos(Vector3D(0, 0, -50));
	e.add(p);
	p = new Pared(100);
	p->setPos(Vector3D(0, 0, 50));
	e.add(p);
	p = new Pared(100);
	p->setPos(Vector3D(-50, 0, 0));
	p->setVertical(true);
	e.add(p);
	p = new Pared(100);
	p->setPos(Vector3D(50, 0, 0));
	p->setVertical(true);
	e.add(p);

	for (double i = -3; i<4; i++) {
		for (double j = 0 - 3; j<4; j++) {
			f = new Esfera();
			f->setPos(Vector3D(i / 2, i*j / 4, j / 2));
			f->setVel(Vector3D(i*j / 5, 0, 0.7));
			f->setCol(Vector3D(getRand(1), getRand(1), 0));
			f->setF(Vector3D(0, -0.98, 0));
			f->setM(1);
			f->setR(0.1);
			e.add(f);
		}
	}
	for (double i = -30; i<31; i += 4) {
		for (double j = -30; j<31; j += 4) {
			f = new Esfera();
			f->setPos(Vector3D(i+getRand(2,-2), 0, j+getRand(2,-2)));
			f->setCol(Vector3D(getRand(1),getRand(1),getRand(1)));
			f->setM(1);
			f->setR(getRand(1,0.1));
			e.add(f);
		}
	}
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, (GLfloat)width / (GLfloat)height, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
}

void idle(void) {
	t += dt;
	e.update(dt);
	displayMe();
	//glutPostRedisplay() ;
}

int main(int argc, char** argv) {
	/*
	ofstream of("prueba.txt");
	if (of.is_open()) {
		of << "hola progando progando" << endl;
		of << "adios adios" << endl;
		of.close();
	}
	else {
		cout << "error al abrir fichero de salida" << endl;
	}
	string s;
	string i, j, k;
	cout << "numero 1: " ;
	cin >> i;
	cout << "numero 2: ";
	cin >> s;
	cout << "i=" << i << " s=" << s << endl;
	cin >> k;
	cout << "l="<<k;
	cin >> i;
	return 0;*/
	srand(10);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(300, 300);                    // window size
	glutInitWindowPosition(500, 500);                // distance from the top-left screen
	glutCreateWindow("BadproG - Hello world :D");    // message displayed on top bar window
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(displayMe);
	glutKeyboardFunc(keyPressed);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mousePress);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}







