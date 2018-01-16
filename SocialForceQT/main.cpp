#include "mainwindow.h"
#include <QApplication>
#include <GL/glut.h>


int main(int argc, char *argv[])
{
    //glut openGl initialization
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
