#include <GL/glut.h>//Es una biblioteca de utilidades para programas OpenGL que principalmente proporciona diversas funciones
					//de entrada/salida con el sistema operativo. Entre las funciones que ofrece se incluyen declaración y manejo
					//de ventanas y la interacción por medio de teclado y ratón. También posee rutinas para el dibujado de diversas primitivas geométricas.
					//También tiene soporte para creación de menús emergentes.
					//Sus objetivos son la creación de código más portable entre diferentes sistemas operativos y hacer OpenGL más simple. Esto
					//quita la necesidad de aprender las APIs específicas de cada sistema operativo. Está pensado para proyectos pequeños.



float pitch = 0;	//Se usa para rotar respecto a x
float yaw = 0;		//Se usa para rotar respecto a y
float roll = 0;		//se usa para rotar respecto a z
int mx = -1;		//Aún no ha sido utilizada
int my = -1;		//Aún no ha sido utilizada
double t = 0;
double dt = 1.0f;

#include "vector3d.h"
#include "solido.h"

Solido* teteras=nullptr;
Solido cubos[2];
Vector3D gravedad;

void displayMe(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//sets the bitplane area of the window to values previously selected by glClearColor, glClearIndex, glClearDepth, glClearStencil,
														//and glClearAccum. Multiple color buffers can be cleared simultaneously by selecting more than one buffer at a time using glDrawBuffer.
														//glClear takes a single argument that is the bitwise OR of several values indicating which buffer is to be cleared.The values are as follows:
															//GL_COLOR_BUFFER_BIT:	Indicates the buffers currently enabled for color writing.
															//GL_DEPTH_BUFFER_BIT:	Indicates the depth buffer.
															//GL_ACCUM_BUFFER_BIT:	Indicates the accumulation buffer.
															//GL_STENCIL_BUFFER_BIT:Indicates the stencil buffer.

	glLoadIdentity();	//replaces the current matrix with the identity matrix.

	glTranslatef(0.0f, 0.0f, -3.0f);	// produces a translation by x y z . The current matrix is multiplied by this translation matrix, with the product replacing the current			
										//matrix. Parameters: (x,y,z), Specify the x, y, and z coordinates of a translation vector.

	glRotatef(pitch, 1.0, 0.0, 0.0);//produces a rotation of angle degrees around the vector x y z .The current matrix is multiplied by a rotation matrix with the product replacing
	glRotatef(yaw, 0.0, 1.0, 0.0);	//the current matrix. Parameters: (angle,x,y,z), specifies the angle of rotation in degrees and specify the x, y, and z coordinates of a vector, respectively.
	glRotatef(roll, 0.0, 0.0, 1.0);
	GLfloat lightpos[] = { 5.0,15.0,5.0,0.0 }; //se define un array de floats con la posición de la luz (GLfloat es para el cross-platform, es decir, problemas al ejecutarlos en distintos SO)

	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);	//returns light source parameter values. Parameters:
													//light:	The identifier of a light. The number of possible lights depends on the implementation, but at least eight lights are supported.
																//They are identified by symbolic names of the form GL_LIGHTi
													//pname:	A light source parameter for light. In this case, GL_POSITION, check https://docs.microsoft.com/en-us/windows/desktop/opengl/gllightfv
													//params:	Specifies the value that parameter pname of light source light will be set to.

	glColor3f(1.0f, 0.0f, 0.0f);	//set the current color, al ser 3f, los parámetros son red, green y blue, y además floats. Si fuera 4f habría un cuarto valor para alpha.

	glBegin(GL_POLYGON);			// glBegin and glEnd delimit the	vertices that define a primitive or a groupof like primitives. glBegin accepts a single	argument that specifies	which of ten
	glVertex3f(0.0, 0.0, 0.0);		//ways the vertices are interpreted.Taking n as an integer count starting at one, and N as the	total number of	vertices specified.
	glVertex3f(0.5, 0.0, 0.0);		//In this case, we've used GL_POLYGON that draws a single, convex polygon.  Vertices 1	through	N define this polygon.
	glColor3f(0.0f, 1.0f, 0.0f);	//Al poner otro color se interpola entre vértices
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.0, 0.0, 0.5);
	glRotatef(t / 30, 0.0, 1.0, 0.0);
	glEnd();

	for (int i = 0; i < 2; i++) {
		teteras[i].renderTetera();
		//cubos[i].renderCubo();
	}
	glPushMatrix(); 
	glTranslatef(2, 0, 0);			//Este método mueve 
	glRotatef(t/10, 1.0, 0.0, 0.0);
	glColor3f(0, 0.5f, 0);
	glutSolidCube(0.6);
	glPopMatrix();

	glFlush();	//force execution of GL commands in finite time, check https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glFlush.xml

	glutSwapBuffers();	//swaps the buffers of the current window if double buffered. Check https://www.opengl.org/resources/libraries/glut/spec3/node21.html
}
void idle(void) {
	t += dt;
	Vector3D v;	//Variable auxiliar
	for (int i = 0; i < 2; i++) {

		v = teteras[i].getPos() + (teteras[i].getVel()*dt);
		teteras[i].setPos(v);
		
		v = teteras[i].getVel() + (gravedad * dt);
		teteras[i].setVel(v);


		if (teteras[i].getPos().getX() >= 2 || teteras[i].getPos().getX() <= -2) {
			v=teteras[i].getVel();
			double d = v.getX()*-1;
			v.setX(d);
			teteras[i].setVel(v);
		}
		if (teteras[i].getPos().getZ() >= 2 || teteras[i].getPos().getZ() <= -2) {
			v = teteras[i].getVel();
			double d = v.getZ()*-1;
			v.setZ(d);
			teteras[i].setVel(v);
		}
		if (teteras[i].getPos().getY() <= 0) {
			v = teteras[i].getVel();
			double d = v.getY()*-0.9;
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


		if (cubos[i].getPos().getX() >= 2 || cubos[i].getPos().getX() <= -2) {
			v = cubos[i].getVel();
			double d = v.getX()*-1;
			v.setX(d);
			cubos[i].setVel(v);
		}
		if (cubos[i].getPos().getZ() >= 2 || cubos[i].getPos().getZ() <= -2) {
			v = cubos[i].getVel();
			double d = v.getZ()*-1;
			v.setZ(d);
			cubos[i].setVel(v);
		}
		if (cubos[i].getPos().getY() <= 0) {
			v = cubos[i].getVel();
			double d = v.getY()*-0.99;
			v.setY(d);
			cubos[i].setVel(v);

			v = cubos[i].getPos();
			v.setY(0);
			cubos[i].setPos(v);
		}
	}
	displayMe();
	//glutPostRedisplay();
}
void init(void) {
	//glEnable and glDisable enable and disable various capabilities. Use glIsEnabled or glGet to determine the current setting of any capability.

	glEnable(GL_DEPTH_TEST);			//If enabled, do depth comparisons and update the depth buffer. 
	glEnable(GL_LIGHTING);				//If enabled, use the current lighting parameters to compute the vertex color.
	glEnable(GL_LIGHT0);				//If enabled, include light i in the evaluation of the lighting equation.
	glEnable(GL_COLOR_MATERIAL);		//If enabled, have ambient and diffuse material parameters track the current color.

	glClearColor(0.0, 0.0, 0.0, 0.0);	//specifies the red, green, blue, and alpha values used by glClear to clear the color buffers. Values specified by glClearColor are clamped to the range [0,1].
	for (int i = 0; i < 2; i++) {
		Vector3D v;
		v = teteras[i].getPos();
		v.setX(i * 2+0.5);
		v.setY(1);
		v.setZ(-1);
		teteras[i].setPos(v);

		v = teteras[i].getCol();
		v.setX(1.0);
		v.setY(0.0);
		v.setZ(i/2);
		teteras[i].setCol(v);

		v = teteras[i].getVel();
		v.setX(0.01);
		v.setY(0.01);
		v.setZ(0.01*(i+1));
		teteras[i].setVel(v);

		v = cubos[i].getPos();
		v.setX(i);
		v.setY(1.5);
		v.setZ(-2);
		cubos[i].setPos(v);

		v = cubos[i].getCol();
		v.setX(0.5);
		v.setY(0.0);
		v.setZ(i / 2.5);
		cubos[i].setCol(v);

		v = cubos[i].getVel();
		v.setX(0.01);
		v.setY(0.0);
		v.setZ(0.01);
		cubos[i].setVel(v);
		
		
	}
	gravedad.setX(0);
	gravedad.setY(-0.000098);
	gravedad.setZ(0);
	
}
void reshape(int width, int height) {
	glViewport(0, 0, width, height);	//specifies the affine transformation of x and y from normalized device coordinates to window coordinates.
										//Toma los valores en el orden: x,y,width,height siendo:
											//x,y:			Specify the lower left corner of the viewport rectangle, in pixels. The initial value is (0,0).
											//width,height: Specify the width and height of the viewport.

	glMatrixMode(GL_PROJECTION);		//sets the current matrix mode. mode can assume one of four values:
											//GL_MODELVIEW:		Applies subsequent matrix operations to the modelview matrix stack.
											//GL_PROJECTION:	Applies subsequent matrix operations to the projection matrix stack.
											//GL_TEXTURE:		Applies subsequent matrix operations to the texture matrix stack.
											//GL_COLOR:			Applies subsequent matrix operations to the color matrix stack.

	glLoadIdentity();	//replaces the current matrix with the identity matrix.

	gluPerspective(90.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200.0f);	//specifies a viewing frustum into the world coordinate system. In general, the aspect ratio in gluPerspective should
																			//match the aspect ratio of the associated viewport. For example, aspect = 2.0 means the viewer's angle of view is twice
																			//as wide in x as it is in y. If the viewport is twice as wide as it is tall, it displays the image without distortion.
																			//Los parámetros son (fovy,aspect,zNear,zFar):
																				//fovy:		Specifies the field of view angle, in degrees, in the y direction.
																				//aspect:	Specifies the aspect ratio that determines the field of view in the x direction.
																				//zNear:	Specifies the distance from the viewer to the near clipping plane(always positive).
																				//zFar:		Specifies the distance from the viewer to the far clipping plane(always positive).

	glMatrixMode(GL_MODELVIEW);
}
void mouseMoved(int x, int y) {	//función para detectar el movimiento del ratón y modificar pitch y yaw en base a ello
	if (mx >= 0 && my >= 0) {	//si se detecta mx y my modificar pitch y yaw
		pitch += y - my;
		yaw += x - mx;
	}
	mx = x;
	my = y;
	glutPostRedisplay();
}
void mousePress(int button, int state, int x, int y) {			//si se pulsa click tener en cuenta el movimiento del ratón
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mx = x;
		my = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mx = -1;
		my = -1;
	}
}
void keyPressed(unsigned char key, int x, int y) { //En este método se tendrán en cuenta las teclas pulsadas para modificar pitch y yaw, y girar de esta forma las figuras
	Vector3D v, r;
	v = teteras[0].getPos();
	r = teteras[1].getCol();
	switch (key) { //En el caso de que se pulsen teclas
		case'q': case 'Q': pitch+=5; break;	//Aumentar pitch
		case'a': case 'A': pitch-=5; break;	//Disminuir pitch
		case'w': case 'W': yaw+=5; break;	//Aumentar yaw
		case's': case 'S': yaw-=5; break;	//Disminuir yaw
		case'e': case 'E': roll+=5; break;	//aumentar roll
		case'd': case 'D': roll-=5; break;	//disminuir roll
		/*case'p': case 'P': v.setX(v.getX()+0.1); break;
		case'o': case 'O': v.setX(v.getX() -0.1); break;
		case'i': case 'I': v.setY(v.getY() + 0.01); break;*/

	}
	teteras[0].setPos(v);
	teteras[1].setCol(v);
	glutPostRedisplay();	//marca a la ventana de visualización como "needing to be redisplayed". De esta forma en la siguiente iteración la ventana se actualizará.
							//Esto se hace en este método únicamente ya que el escenario sólo cambiará, en nuestro caso, si modificamos los valores de pitch o yaw.
}
int main(int argc, char** argv) {	//argc (argument count) cuenta los parámetros que fueron pasados al programa como un número
									//argv (argument value) almacena los datos, en caso de ser más de uno se almacenarán como un array
									//si pongo en la línea de comandos ">>Base 5 6", entonces argc = 3, argv[0]="Base", argv[1]=5, argv[2]=6
									//Poner ** al declarar una variable significa declarar un puntero a un puntero a la variable. Por ejemplo *int significa que en lugar de
									//crear un int, creas un puntero a un int
	teteras = new Solido[2];
	glutInit(&argc, argv);	//Función que inizializa la librería GLUT.
							//El signo & indica que al pasar argc se pasa el objeto real, y no una copia, es decir, manda la dirección el objeto
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	//se usa al crear top-level windows (a window that has no parent, that is, a window that's not a child window. It can be displayed
																//anywhere in the screen), subwindows y overlays "to determine the OpenGl mode for the to-be-created window or overlay".
																//GLUT_DOUBLE: Bit mask to select a double buffered window. This overrides GLUT_SINGLE if it is also specified.
																//GLUT_RGBA: Bit mask to select an RGBA mode window. This is the default if neither GLUT_RGBA nor GLUT_INDEX are specified.
																//GLUT_DEPTH: Bit mask to select a window with a depth buffer.
	
	glutInitWindowSize(300, 300);		//Windows created by glutCreateWindow will be requested to be created with the current initial window position and size
	glutInitWindowPosition(500, 500);

	glutCreateWindow("BadproG - Hello world :D");	//creates a top-level window. The name will be provided to the window system as the window's name. The intent is that the window system
													//will label the window with the name. The display state of a window is initially for the window to be shown. But the window's display state
													//is not actually acted upon until glutMainLoop is entered. This means until glutMainLoop is called, rendering to a created window is ineffective
													//because the window can not yet be displayed.

	init();

	glutReshapeFunc(reshape);				//sets the reshape callback for the current window. The reshape callback is triggered when a window is reshaped. A reshape callback is also
											//triggered immediately before a window's first display callback after a window is created or whenever an overlay for the window is established.
											//The width and height parameters of the callback specify the new window size in pixels. Before the callback, the current window is set to the window
											//that has been reshaped.

	glutDisplayFunc(displayMe);				//sets the display callback for the current window. When GLUT determines that the normal plane for the window needs to be redisplayed, the display
											//callback for the window is called. Before the callback, the current window is set to the window needing to be redisplayed and (if no overlay display
											//callback is registered) the layer in use is set to the normal plane. The display callback is called with no parameters. The entire normal plane region
											//should be redisplayed in response to the callback (this includes ancillary buffers if your program depends on their state).
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mousePress);
	glutKeyboardFunc(keyPressed);
	glutIdleFunc(idle);
	glutMainLoop();							//Hace que el método main se repita indefinidamente. glutMainLoop enters the GLUT event processing loop. This routine should be called at most once in a
											//GLUT program. Once called, this routine will never return. It will call as necessary any callbacks that have been registered.

	return 0;	//En c++ necesitamos que el programa siempre devuelva algo, por eso el main es un int, este 0 no tiene ningún valor, solo sirve para que se ejecute bien el programa y como indicación
				//de que el programa a terminado de ejecutarse con éxito ya que ha llegado a este punto
}