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

//functions declaration
void init();
void display();
void drawWalls();
void drawAgents();
void update();
void normalKey(unsigned char key, int xMousePos, int yMousePos);
void computeFPS();

//main function only implement GUI
int main(int argc, char **argv){

	glutInit(&argc, argv);									   // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Set display mode  Default mode used
	glutInitWindowSize(winWidth, winHeight);				   // Set window width and height
	glutInitWindowPosition(90, 90);							   // Set window position
	glutCreateWindow("Crowd Simulation using Social Force");   // Set window title and create display window
	
	init(); //create agents and walls

	glutDisplayFunc(display);
	glutKeyboardFunc(normalKey);
	glutIdleFunc(update);

	glutMainLoop(); // Enter GLUT's main loop

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the colour and depth buffer

	glPushMatrix();
		glScalef(1.0, 1.0, 1.0);
		drawWalls();
		drawAgents();
	glPopMatrix();

	//showInformation();

	glFlush();
	glutSwapBuffers();
}

void init()
{
	int numberOfAgent = 300;
	socialForce.createWalls();
	socialForce.createAgents(numberOfAgent);
}

void drawAgents(){
	vector<Agent> agents = socialForce.getAgents();
	//cout << agents.size() << endl;
	glPushMatrix();
		for (Agent tmpAgent: agents)
			if (tmpAgent.getID() != -1){
			glColor3f(0.0f, 0.0f, 1.0f);
			glPointSize(10.0f);
		
			glBegin(GL_POINTS);
				Point tmpPoint = tmpAgent.getPosition();
				//cout << tmpPoint.getX() << " " << tmpPoint.getY() << endl;
				glVertex2f(tmpPoint.getX(), tmpPoint.getY());
				//glVertex2f(0.0, 0.0);
			glEnd();	
		}
	glPopMatrix();
}

void drawWalls() {
	vector<Wall> walls = socialForce.getWalls();
	glColor3f(1.0, 0.0, 0.0);
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

void update(){
	static int preTime = 0;
	int frameTime, curTime;
	
	curTime = glutGet(GLUT_ELAPSED_TIME);
	frameTime = curTime - preTime;
	preTime = curTime;

	socialForce.nextState(static_cast<float>(frameTime) / 2000);

	computeFPS();
	glutPostRedisplay();
	glutIdleFunc(update);
}

void computeFPS() {
	static int frameCount = 0;	// Stores number of frames
	int currTime, frameTime;	// Store time in milliseconds
	static int prevTime;		// Stores time in milliseconds

	frameCount++;

	currTime = glutGet(GLUT_ELAPSED_TIME);	// Get time in milliseconds since 'glutInit()' called
	frameTime = currTime - prevTime;

	if (frameTime > 1000) {
		float fps = frameCount / (static_cast<float>(frameTime) / 1000);	// Compute the number of FPS
		prevTime = currTime;
		frameCount = 0;												// Reset number of frames
	}
}