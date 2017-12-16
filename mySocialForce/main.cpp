
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <GL/glut.h>
#include "SocialForce.h"

using namespace std;

GLsizei winWidth = 992;  // Window width (16:9 ratio)
GLsizei winHeight = 558; // Window height (16:9 ratio)

SocialForce socialForce;
int numberOfAgent = 400;

//functions declaration
void init();
void display();
void drawWalls();
void normalKey(unsigned char key, int xMousePos, int yMousePos);

//main function only implement GUI
int main(int argc, char **argv){

	glutInit(&argc, argv);									   // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Set display mode  Default mode used
	glutInitWindowSize(winWidth, winHeight);				   // Set window width and height
	glutInitWindowPosition(90, 90);							   // Set window position
	glutCreateWindow("Crowd Simulation using Social Force");   // Set window title and create display window
	
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(normalKey);

	glutMainLoop();
	glutMainLoop(); // Enter GLUT's main loop

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the colour and depth buffer

	glPushMatrix();
		glScalef(1.0, 1.0, 1.0);
		drawWalls();
	glPopMatrix();
		//examples draw triangles
		/*glPushMatrix();
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, 0);
		glVertex2f(0, 0.5);
	glEnd();
	glPopMatrix();*/

	glutSwapBuffers();
}

void init()
{
	srand(1604010629); // Seed to generate random numbers
	socialForce.createWalls();
	socialForce.createAgents(numberOfAgent);
}

void drawWalls() {
	vector<Wall> walls = socialForce.getWall();
	//glColor3f(0.2F, 0.2F, 0.2F);
	glPushMatrix();
		for (Wall tmpWall : walls) {
			glBegin(GL_LINES);
				Line tmpLine = tmpWall.getLine();
				Point tmpFirst = tmpLine.getFirst();
				Point tmpSecond = tmpLine.getSecond();
				glVertex2f(tmpFirst.getX(),tmpFirst.getY());
				glVertex2f(tmpSecond.getX(), tmpSecond.getY());
			glEnd();
		}
	glPopMatrix();
}

void normalKey(unsigned char key, int xMousePos, int yMousePos)
{
	switch (key){
		case 27: // ASCII character for Esc key
			exit(0); // Terminate program
			break;
	}
}