#include <GL/glut.h>
float pitch = 0;	//Se usa para rotar respecto a x
float yaw = 0;		//Se usa para rotar respecto a y
float roll = 0;		//se usa para rotar respecto a z
int mx = -1;
int my = -1;
double t = 0;
double dt = 0.01f;

#include "vector3D.h"
#include "Solido.h"
#include "cubo.h"
#include "esfera.h"
#include "escena.h"
#include "cilindro.h"
#include "camara.h"
#include "pared.h"
#include "toro.h"
#include "compuesto.h" 

//Solido* teteras=nullptr;
//Esfera esferas[2];
//Cubo cubos[2];
Escena e;
Camara cam(0, 0, 3);
Vector3D gravedad;
Esfera sf;

CamaraFPS camf(0, 0, 0);

void displayMe(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/*Camara*/

	//glTranslatef(0.0f, 0.0f, -10.0f);
	//glRotatef(pitch, 1.0, 0.0, 0.0);
	//glRotatef(yaw, 0.0, 1.0, 0.0);
	//glRotatef(roll, 0.0, 0.0, 1.0);
	camf.render();
	GLfloat lightpos[] = { 5.0,15.0,5.0,0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glColor3f(1.0f, 0.0f, 0.0f);

	/*Escena*/

	/*for (int i = 0; i < 2; i++) {
		teteras[i].renderTetera();
		cubos[i].render();
		esferas[i].render();
	}*/
	e.render();

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(t / 10, 1.0, 0.0, 0.0);
	glColor3f(0, 0.5f, 0);
	glutSolidCube(0.6);
	glPopMatrix();

	glFlush();

	glutSwapBuffers();
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
	for (int i = 0; i < 2; i++) {
		Cubo* c = nullptr;
		c = new Cubo(Vector3D(0, 1, i + 1));
		c->setCol(Vector3D(1, 0, i));
		c->setVel(Vector3D(0.01, 1 + i * 1, 0.03));
		c->setS(0.25*(i + 1));
		e.add(c);

		Esfera* sf = nullptr;
		sf = new Esfera(Vector3D(0, 1, i + 1), Vector3D(1, i, 0));
		sf->setVel(Vector3D(0.015, 1 + i * 1, -0.003));
		e.add(sf);




	}
	Esfera *f;
	Cilindro *cl;
	Compuesto *arbol, *arbol0;
	arbol = new Compuesto();
	f = new Esfera();
	f->setPos(Vector3D(0, 10, 0));
	f->setCol(Vector3D(1, 1, 0));
	f->setR(0.1);
	f->setF(Vector3D(0, -0.98, 0));
	f->setM(1);
	arbol->add(f);
	cl = new Cilindro(0.5, 4);
	cl->setPos(Vector3D(0, 4, 0));
	cl->setCol(Vector3D(0, 1, 0));
	cl->setHe(5.5);
	cl->setRad(2.0);
	arbol->add(cl);
	e.add(arbol);
	for (int i = 0; i < 100; i++){
		arbol0 = arbol->clone();
		arbol0->setF(Vector3D(0, -0.98, 0));
		arbol0->setM(1);
		arbol0->setPos(Vector3D(getRand(45, -45), 10, getRand(45, -45)));
		e.add(arbol0);
	}



	Cilindro* cil = nullptr;
	cil = new Cilindro(1.0, 1.0);
	cil->setVel(Vector3D(0.01, 0.2, 0.2));
	cil->setPos(Vector3D(0,100,1));
	cil->setHe(5.5);
	cil->setRad(2.0);
	cil->setF(Vector3D(0, -0.98, 0));
	cil->setCol(Vector3D((getRand(1), 0, 1)));
	cil->setM(1);
	e.add(cil);
	
	
	Pared* par = nullptr;
	par = new Pared();
	par->setPos(Vector3D(0, 2, 1));
	par->setVel(Vector3D(0.01, 0.1, 0.2));
	par->setF(Vector3D(0, -0.98, 0));
	par->setM(1);
	e.add(par);
	par->setCol(Vector3D(getRand(1), 0, 1));

	Toro* tor = nullptr;
	tor = new Toro();
	tor->setPos(Vector3D(1, 0, 0));
	tor->setVel(Vector3D(0.0, 0.0, 0.0));
	e.add(tor);
	tor->setCol(Vector3D(1, 0, 0.5));
	

	gravedad.setX(0);
	gravedad.setY(-0.000098);
	gravedad.setZ(0);
	//cout << sf;
	//cout << par;

}
void idle(void) {
	t += dt;
	e.update(dt);
	/*Vector3D v;	//Variable auxiliar
	for (int i = 0; i < 2; i++) {

		v = teteras[i].getPos() + (teteras[i].getVel()*dt);
		teteras[i].setPos(v);
		
		v = teteras[i].getVel() + (gravedad * dt);
		teteras[i].setVel(v);


		if (teteras[i].getPos().getX() >= 3 || teteras[i].getPos().getX() <= -3) {
			v=teteras[i].getVel();
			double d = v.getX()*-1;
			v.setX(d);
			teteras[i].setVel(v);
		}
		if (teteras[i].getPos().getZ() >= 3 || teteras[i].getPos().getZ() <= -3) {
			v = teteras[i].getVel();
			double d = v.getZ()*-1;
			v.setZ(d);
			teteras[i].setVel(v);
		}
		if (teteras[i].getPos().getY() <= 0) {
			v = teteras[i].getVel();
			double d = v.getY()*-1;
			v.setY(d);
			teteras[i].setVel(v);

			v = teteras[i].getPos();
			v.setY(0);
			teteras[i].setPos(v);
		}

	}
	for (int i = 0; i < 2; i++) {
		
		
		v = cubos[i].getPos() + (cubos[i].getVel()*dt);
		cubos[i].setPos(v);

		v = cubos[i].getVel() + (gravedad * dt);
		cubos[i].setVel(v);


		if (cubos[i].getPos().getX() >= 3 || cubos[i].getPos().getX() <= -3) {
			v = cubos[i].getVel();
			double d = v.getX()*-1;
			v.setX(d);
			cubos[i].setVel(v);
		}
		if (cubos[i].getPos().getZ() >= 3 || cubos[i].getPos().getZ() <= -3) {
			v = cubos[i].getVel();
			double d = v.getZ()*-1;
			v.setZ(d);
			cubos[i].setVel(v);
		}
		if (cubos[i].getPos().getY() <= 0) {
			v = cubos[i].getVel();
			double d = v.getY()*-1;
			v.setY(d);
			cubos[i].setVel(v);

			v = cubos[i].getPos();
			v.setY(0);
			cubos[i].setPos(v);
		}
	}

	for (int i = 0; i < 2; i++) {


		v = esferas[i].getPos() + (esferas[i].getVel()*dt);
		esferas[i].setPos(v);

		v = esferas[i].getVel() + (gravedad * dt);
		esferas[i].setVel(v);


		if (esferas[i].getPos().getX() >= 3 || esferas[i].getPos().getX() <= -3) {
			v = esferas[i].getVel();
			double d = v.getX()*-1;
			v.setX(d);
			esferas[i].setVel(v);
		}
		if (esferas[i].getPos().getZ() >= 3 || esferas[i].getPos().getZ() <= -3) {
			v = esferas[i].getVel();
			double d = v.getZ()*-1;
			v.setZ(d);
			esferas[i].setVel(v);
		}
		if (esferas[i].getPos().getY() <= 0) {
			v = cubos[i].getVel();
			double d = v.getY()*-1;
			v.setY(d);
			esferas[i].setVel(v);

			v = esferas[i].getPos();
			v.setY(0);
			esferas[i].setPos(v);
		}
	}*/
	displayMe();
	//glutPostRedisplay;
}
void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);											
	glLoadIdentity();	
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200.0f);	
	glMatrixMode(GL_MODELVIEW);
}



void mouseMoved(int x, int y) {	
	if (mx >= 0 && my >= 0) {
		//pitch += y - my;
		//yaw += x - mx;
		Vector3D r;
		r = camf.getRot() + Vector3D(y - my, x - mx, 0);
		camf.setRot(r);
	}
	mx = x;
	my = y;
	glutPostRedisplay();
}
void mousePress(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mx = x;
		my = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mx = -1;
		my = -1;
	}
}
void keyPressed(unsigned char key, int x, int y) {
	Vector3D v, r;
	//v = teteras[0].getPos();
	//r = teteras[1].getCol();
	switch (key) {
		case'q': case 'Q': pitch+=5; break;	//Aumentar pitch
		case'a': case 'A': pitch-=5; break;	//Disminuir pitch
		case'w': case 'W': yaw+=5; break;	//Aumentar yaw
		case's': case 'S': yaw-=5; break;	//Disminuir yaw
		case'e': case 'E': roll+=5; break;	//aumentar roll
		case'd': case 'D': roll-=5; break;	//disminuir roll
		case 'o': case 'O': camf.setRot(camf.getRot() + Vector3D(1, -1, 0)); break;
		case 'p': case 'P': camf.setRot(camf.getRot() + Vector3D(1, 1, 0)); break;
		case 'y': case 'Y': camf.update(-dt * 2); break;
		case 'n': case 'N': camf.update(dt * 2); break;
	}
	//teteras[0].setPos(v);
	//teteras[1].setCol(v);
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	srand(10);
	//teteras = new Solido[2];
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("BadproG - Hello world :D");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(displayMe);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mousePress);
	glutKeyboardFunc(keyPressed);
	glutIdleFunc(idle);
	glutMainLoop();

	return 0;
}