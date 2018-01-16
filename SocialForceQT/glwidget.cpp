#include "glwidget.h"
#include <GL/glut.h>
#include <math.h>
#include "XMLInitializer.h"

//rainbow colors from purple to red
const float GLWidget::COLORS[40][3] = {{153.0/255,0,76.0/255},
                                    {76.0/255,0,154.0/255},
                                  {102.0/255,0,204.0/255},
                                  {107.0/255,0,1},
                                  {0,0,153.0/255},
                                  {0,0,204.0/255},
                                  {0,0,1},
                                  {51.0/255,51.0/255,1},
                                  {0,76.0/255,153.0/255},
                                  {0,102.0/255,204.0/255},
                                  {0,128.0/255,1},
                                  {51.0/255,153.0/255,1},
                                  {0,153.0/255,153.0/255},
                                  {0,204.0/255,204.0/255},
                                  {0,1,1},
                                  {31.0/255,1,1},
                                  {0,153.0/255,76.0/255},
                                  {0,204.0/255,102.0/255},
                                  {0,1,128.0/255},
                                  {51.0/255,1,153.0/255},
                                  {0,153.0/255,0},
                                  {0,204.0/255,0},
                                  {0,1,0},
                                  {51.0/255,1,51.0/255},
                                  {76.0/255,153.0/255,0},
                                  {102.0/255,204.0/255,0},
                                  {128.0/255,1,0},
                                  {153.0/255,1,51.0/255},
                                  {153.0/255,153.0/255,0},
                                  {204.0/255,204.0/255,0},
                                  {1,1,0},
                                  {1,1,51.0/255},
                                  {153.0/255,76.0/255,0},
                                  {204.0/255,102.0/255,0},
                                  {1,128.0/255,0},
                                  {1,153.0/255,51.0/255},
                                  {1,51.0/255,51.0/255},
                                  {1,0,0},
                                  {204.0/255,0,0},
                                  {153.0/255,0,0}
                                  };

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->showDirection=false;
    this->showForces=false;
    this->showWayPoints=false;
    this->interval=0.03;

    bool isCorrect=false;
    socialForce = XMLInitializer::initSocialForce("exampleScenarios/scenario3.xml",&isCorrect);
    if(!isCorrect)
        initializeSocialForce();

    connect(&timer, SIGNAL(timeout()),this, SLOT(onUpdate()));
    timer.start(10);
}

void GLWidget::onUpdate() {
    if(shouldPaint) {
            socialForce.nextState(interval);
            update();

    }
}

void GLWidget::initializeSocialForce()
{
    bool isCorrect = false;
    while(!isCorrect) {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open XML file"), "", tr("XML files (*.xml)"));
        std::string s = fileName.toStdString();
        socialForce = XMLInitializer::initSocialForce(s,&isCorrect);
        vector<Wall> myAgents = socialForce.getWalls();
    }
}

void GLWidget::initializeGL()
{


    glClearColor(0.9,0.9,0.9,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,0,0);
    if(showWayPoints)
        drawWayPoints();

    drawWalls();
    drawAgents();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);

    //update();
}

int GLWidget::getCoeffForForce(float force)
{
    force=force*2.0;
    if (force<0.5) force=0.5;
    else if (force>2.5) force=2.49;
    force=force-0.5;
    force=force*20;

    return int(force);

}

void GLWidget::drawDirection(float xPos, float yPos, Vector2 v)
{
    glColor3f(0.0, 0.0, 0.0);

            glBegin(GL_LINES);
                glVertex2f(xPos,yPos);
                glVertex2f(xPos + v.getX()/3.0, yPos + v.getY()/3.0);
            glEnd();

}

void GLWidget::drawWayPoints()
{
    map<int,WayPoint*> wp = socialForce.getAllWayPoints();
    glColor3f(0.098, 0.098, 0.439);
    glPushMatrix();
        for (map<int,WayPoint*>::iterator it=wp.begin(); it!=wp.end(); ++it) {
            drawCircle(it->second->getPosition().getX(),it->second->getPosition().getY(),it->second->getRadius(),30);
        }
    glPopMatrix();
}

void GLWidget::drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / float(num_segments);
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = r;//we start at angle = 0
    float y = 0;

    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();
}

void GLWidget::drawWalls()
{
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

void GLWidget::drawAgents()
{
    vector<Agent> agents = socialForce.getAgents();
        glPushMatrix();
            for (Agent tmpAgent: agents)
                if (tmpAgent.getID() != -1){
                    if(showDirection)
                        drawDirection(tmpAgent.getPosition().getX(),tmpAgent.getPosition().getY(),
                                      tmpAgent.getCurrentSpeed());

                    glPointSize(5.0);
                    if(showForces) {
                        int coe = getCoeffForForce(tmpAgent.getActualForce());
                        glColor3f(COLORS[coe][0],COLORS[coe][1],COLORS[coe][2]);
                    } else glColor3f(0.0f, 0.0f, 1.0f);

                    glBegin(GL_POINTS);
                        Point tmpPoint = tmpAgent.getPosition();

                        glVertex2f(tmpPoint.getX(), tmpPoint.getY());

                    glEnd();

            }

        glPopMatrix();
}
