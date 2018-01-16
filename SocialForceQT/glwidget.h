#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include "SocialForce.h"
#include <QFileDialog>

/**
 * @brief The GLWidget class
 * Class manages animation of social force
 * Class uses openGL library
 */
class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    /**
     * @brief initializes SocialForce object from xml file
     */
    void initializeSocialForce();

    /**
     * @brief initialize openGL with glut functions
     */
    void initializeGL();

    /**
     * @brief functions is used each time when update() slot is triggered
     * it paint the view
     */
    void paintGL();

    /**
     * @brief resizeGL is used when viewport is being resized
     * @param w width
     * @param h height
     */
    void resizeGL(int w, int h);

    /**
     * @brief socialForce main object which gives data to simulation
     */
    SocialForce socialForce;

    /**
     * @brief showForces when true, forces of each agent are drawn
     */
    bool showForces;

    /**
     * @brief showDirection when true, agents' directions are drawn
     */
    bool showDirection;

    /**
     * @brief showWayPoints when true, wayPoints are drawn
     */
    bool showWayPoints;

    /**
     * @brief shouldPaint when true, animation is drawn
     * It is used to stop/start animation
     */
    bool shouldPaint = false;

    /**
     * @brief interval time in miliseconds, stepTime used to calculate pedestians animation
     */
    float interval;

    /**
     * @brief COLORS matrix with rgb colors as float numebers.
     * Rainbow colors from purple to red.
     */
    const static float COLORS[40][3];

private:
    int getCoeffForForce(float force);
    float dx = 0.0;
    void drawDirection(float xPos, float yPos,Vector2 v);
    void drawWayPoints();
    void drawWalls();
    void drawAgents();
    void drawCircle(float cx, float cy, float r, int num_segments);
    QTimer timer;
public slots:
    /**
     * @brief onUpdate slot which manages triggering of paintGL() function
     */
    void onUpdate();
};

#endif // GLWIDGET_H
