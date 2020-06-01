/*
*  Paluka-L-System.cpp
*  Erik Paluka
*  November, 2011
*
*	This program models the growth process of plant development.
*   It draws a growing plant.
*	It is an L-system or Lindenmayer system
*	It starts off with an intil axiom string, and replacing that with its production rule.
*	This continues until a depth value is reached. The plant is then drawn.
*
*	I first draw the ground (the plane that the tree is sitting in) using triangles.
*	I then expand the L-System string by iterating through the string starting at
*	the beginning and replacing the letters with their production rules.
*	I added randomness to the model by creating a pseudo random number between 0 and 1.
*	The value of the random number dictates which production rule a letter gets replaced with.
*	I expand the string recursively, and pass a depth variable as a parameter, decreasing its value each call.
*	When the value of the depth variable reaches 0, I draw the L-System and return.
*	When I draw the L-System, I draw the branch width (line width) based on the depth of the tree.
*	Each time a push matrix operation happens, I decrease the depth. Each time a pop matrix operation happens,
*	I increase the depth. I draw the branches using lines. I draw the leaves using triangles.
*	My tree is 3D. I did this by rotating in all three axis when a clockwise or counter-clockwise rotation occurs.
*
*/

#include <Windows.h>
#include <Mmsystem.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>

using namespace std;

//DEPTH -> Altura
const float PI = 3.14F, DEPTH = 4;

// Start and end of camera movement
const int ENDX = 10, STARTX = -500;

// Angle of branches, and depth of tree
float ANGLE = 20, depth = 0;

vector<string>* trees = new vector<string>();

double lastTime = 0, elapsedTime = 0, lastElapsedTime = 0;

bool cam = false;

float eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ, fieldOfView, length = 0.001F, num = 0, incr = 0.1F;

// Grosor tronco
float lineWidth = 6;

// L-System
string str = "X";

void push() {
	glPushMatrix();
	if (lineWidth > 0)
		lineWidth -= 1;
}

void pop() {
	glPopMatrix();
	lineWidth += 1;
}

void rotL() {
	glRotatef(ANGLE, 1, 0, 0);
	glRotatef(ANGLE * 4, 0, 1, 0);
	glRotatef(ANGLE, 0, 0, 1);
}

void rotR() {
	glRotatef(-ANGLE, 1, 0, 0);
	glRotatef(ANGLE * 4, 0, 1, 0);
	glRotatef(-ANGLE, 0, 0, 1);
}

void leaf() {

	glPushAttrib(GL_LIGHTING_BIT);//saves current lighting stuff

	//glColor3f(0.50, 1.0, 0.0);
	GLfloat ambient[4] = { 0.50F, 1.0F, 0.0F };    // ambient reflection
	GLfloat specular[4] = { 0.55F, 1.0F, 0.0F };   // specular reflection
	GLfloat diffuse[4] = { 0.50F, 0.9F, 0.0F };   // diffuse reflection

	// set the ambient reflection for the object
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	// set the diffuse reflection for the object
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	// set the specular reflection for the object      
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	// set the size of the specular highlights
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0);

	//glutSolidCube(depth+1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0);
	glVertex3f(0.2F, 0, 0.3F);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(-0.2F, 0, -0.3F);
	glVertex3f(0, 1, 0);
	glEnd();
	glPopAttrib();
}

void drawLine() {

	glPushAttrib(GL_LIGHTING_BIT);//saves current lighting stuff
	
	//glColor3f(0.55, 0.27, 0.07);
	GLfloat ambient[4] = { 0.55F, 0.27F, 0.07F };    // ambient reflection
	GLfloat specular[4] = { 0.55F, 0.27F, 0.07F };   // specular reflection
	GLfloat diffuse[4] = { 0.55F, 0.27F, 0.07F };   // diffuse reflection


	// set the ambient reflection for the object
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	// set the diffuse reflection for the object
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);

	// set the specular reflection for the object      
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glLineWidth(lineWidth);

	glBegin(GL_LINES);

	glVertex3f(0, 0, 0);
	glVertex3f(0, length, 0);
	glEnd();

	glTranslatef(0, length, 0);
	glPopAttrib();
}

void draw() {

	string ch = "";
	string LSystem = trees->at(depth);
	for (int i = 0; i < LSystem.length(); i++) {
		ch = LSystem.at(i);

		if (ch.compare("D") == 0 || ch.compare("X") == 0) {
			drawLine();
		}
		else if (ch.compare("[") == 0) {
			push();
		}
		else if (ch.compare("]") == 0) {
			pop();
		}
		else if (ch.compare("V") == 0) {
			leaf();
		}
		else if (ch.compare("R") == 0) {
			rotR();
		}
		else if (ch.compare("L") == 0) {
			rotL();
		}
	}
}

void expand(float num) {
	string ch = "";

	for (int i = 0; i < str.length(); i++) {
		ch = str.at(i);

		//Arbol 1 / 4 / 5 / 6
		if (ch.compare("D") == 0) {
			str.replace(i, 1, "DD");
			i = i + 1;
		}
		
		//else
		if (ch.compare("X") == 0) {

			if (num < 0.4) {
				//LSystem.replace(i, 1, "D[LX]D[RX]LX");
				// Arbol 1
				//str.replace(i, 1, "D[LXV]D[RXV]LX");
				// Arbol 2
				//str.replace(i, 1, "D[RDXV]D[LDXV]DX");
				// Arbol 3
				//str.replace(i, 1, "D[RXV]D[LXV][X]X");
				// Arbol 4
				//str.replace(i, 1, "D[RX][LX]RX");
				// Arbol 5
				str.replace(i, 1, "D[RX][LX]DX");
				// Arbol 6
				//str.replace(i, 1, "DL[[X]RX]RD[RDX]LX");

			}
			else {
				//LSystem.replace(i, 1, "D[RX]D[LX]RX");sa
				// Arbol 1
				//str.replace(i, 1, "D[RXV]D[LXV]RX");
				// Arbol 2
				//str.replace(i, 1, "D[LDXV]D[RDXV]DX");
				// Arbol 3
				//str.replace(i, 1, "D[LXV]D[RXV]X");
				// Arbol 4
				//str.replace(i, 1, "D[LX][RX]LX");
				// Arbol 5
				str.replace(i, 1, "D[LX][RX]DX");
				// Arbol 6
				//str.replace(i, 1, "DR[[X]LX]LD[LDX]RX");

			}
			//i = i + 13;
			//i = i + 15; // 2 y 3
			//i = i + 13;
			i = i + 10;
			//i = i + 17;
		}

	}
	trees->push_back(str);
}

void display(void) {

	// Color de Fondo
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// start by clearing the screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fieldOfView, 1.0, 1, 2000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, 0, 1, 0);

	glPushMatrix();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushAttrib(GL_LIGHTING_BIT); //saves current lighting stuff
	GLfloat ambient[4] = { 0.82F, 0.41F, 0.12F };    // ambient reflection
	GLfloat diffuse[4] = { 0.82F, 0.41F, 0.12F };   // diffuse reflection 

	// set the ambient reflection for the object
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	// set the diffuse reflection for the object
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);

	glBegin(GL_TRIANGLES);
	glVertex3f(-20, 0, -20);
	glVertex3f(20, 0, -20);
	glVertex3f(20, 0, 20);
	glVertex3f(-20, 0, 20);
	glVertex3f(-20, 0, -20);
	glVertex3f(20, 0, 20);

	glEnd();
	glPopMatrix();
	glPopAttrib();

	draw();
	glutSwapBuffers();
	glutPostRedisplay();
}

void animate() {
	
	if (lastTime == 0)
		lastTime = timeGetTime();

	elapsedTime = timeGetTime() - lastTime;

	// Change the angle to make it blow in the wind
	float numR = (float)rand() / RAND_MAX;

	/*
	if (ANGLE > 21.5) {
		if (numR < 0.5) {
			incr = -0.15F;
		}
		else {
			incr = -0.1F;
		}
	}
	else if (ANGLE < 18.5) {
		if (numR > 0.5) {
			incr = 0.15F;
		}
		else {
			incr = 0.1F;
		}
	}
	*/

	incr = 0;

	ANGLE += incr;
	
	if (depth < DEPTH)
		length += 0.001F;

	if (elapsedTime - lastElapsedTime > 2000 && depth < DEPTH) {
		depth++;
		lastElapsedTime = elapsedTime;
		cout << "a ";

	}
	elapsedTime = elapsedTime / 5000;
	float t = (sin((elapsedTime * PI - PI / 2)) + 1) / 2;
	float p = (1 - t) * STARTX + t * ENDX;

	if (cam)
		eyeX = p;
	
	glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 113:			// q - Exit the program
		exit(0);
		break;
	case 119:			// w - Reset the camera
		fieldOfView = 45;
		eyeX = 150;
		eyeY = 100;
		eyeZ = 150;
		lookX = 0;
		lookY = 50;
		lookZ = 0;
		break;
	case 122:			// z - Reduce the field of view of the camera
		fieldOfView -= 5;
		glutPostRedisplay();
		break;
	case 120:			// x - Increase the field of view of the camera
		fieldOfView += 5;
		glutPostRedisplay();
		break;
	case 115:			// s - Stop moving the camera
		cam = false;
		break;
	case 97:			// a - Move the camera
		cam = true;
		break;
	case 100:			// d - Increase camera X-coordinate
		eyeX++;
		break;
	case 102:			// f - Decrease camera X-coordinate
		eyeX--;
		break;
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Erik Paluka");

	fieldOfView = 45;
	eyeX = 250;
	eyeY = 100;
	eyeZ = 100;
	lookX = 0;
	lookY = 50;
	lookZ = 0;
	srand(time(NULL));
	num = (float)rand() / RAND_MAX;

	// set the lighting
	glShadeModel(GL_SMOOTH);
	GLfloat lightP[4] = { 0.0, 800.0, 0.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightP);

	// set the ambient light colour    
	GLfloat lightA[4] = { 0.0F,0.9F,0.9F,1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightA);

	// set the specular light colour         
	GLfloat lightS[4] = { 0.9F,0.9F,0.9F,1.0F };
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightS);

	// set the diffuse light colour
	GLfloat lightD[4] = { 0.9F,0.9F,0.9F,1.0F };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightD);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/* Use depth buffering for hidden surface elimination. */
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(animate);
	trees = new vector<string>();
	for (int i = 0; i <= DEPTH; i++) {
		expand(num);
	}
	glutMainLoop();
	return 0;
}

