#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "XMLInitializer.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_showForces_clicked(bool checked)
{
    this->ui->myGLWidget->showForces=checked;
}

void MainWindow::on_showDirection_clicked(bool checked)
{
    this->ui->myGLWidget->showDirection=checked;
}

void MainWindow::on_showWayPoints_clicked(bool checked)
{
    this->ui->myGLWidget->showWayPoints=checked;
}


void MainWindow::on_destForceCoe_valueChanged(double arg1)
{
    this->ui->myGLWidget->socialForce.setDestForceCoe(arg1);
}

void MainWindow::on_obstacleForceCoe_valueChanged(double arg1)
{
    this->ui->myGLWidget->socialForce.setObstacleForceCoe(arg1);
}

void MainWindow::on_agentsForceCoe_valueChanged(double arg1)
{
    this->ui->myGLWidget->socialForce.setAgentsForceCoe(arg1);
}


void MainWindow::on_loadScenarioB_clicked()
{
    ui->myGLWidget->initializeSocialForce();
    initSocialForceCoefficients();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->ui->myGLWidget->interval=(float)value/1000;
}

void MainWindow::on_restartB_clicked()
{
    std::string s = this->ui->myGLWidget->socialForce.getSourceFile();
    bool _true;
    this->ui->myGLWidget->socialForce = XMLInitializer::initSocialForce(s,&_true);
    ui->myGLWidget->shouldPaint=true;
    ui->startStopB->setText("Stop");
    initSocialForceCoefficients();
}

void MainWindow::on_startStopB_clicked()
{
    if(ui->startStopB->text() == "Start") {
        ui->myGLWidget->shouldPaint=true;
        ui->startStopB->setText("Stop");
    }
    else {
        ui->myGLWidget->shouldPaint=false;
        ui->startStopB->setText("Start");
    }
}

void MainWindow::on_resetCoefficientsB_clicked()
{
    this->ui->agentsForceCoe->setValue(1.0);
    this->ui->obstacleForceCoe->setValue(1.0);
    this->ui->destForceCoe->setValue(1.0);
    this->ui->myGLWidget->socialForce.setAgentsForceCoe(1.0);
    this->ui->myGLWidget->socialForce.setDestForceCoe(1.0);
    this->ui->myGLWidget->socialForce.setObstacleForceCoe(1.0);
}

void MainWindow::initSocialForceCoefficients()
{
    this->ui->myGLWidget->socialForce.setObstacleForceCoe(this->ui->obstacleForceCoe->value());
    this->ui->myGLWidget->socialForce.setDestForceCoe(this->ui->destForceCoe->value());
    this->ui->myGLWidget->socialForce.setAgentsForceCoe(this->ui->agentsForceCoe->value());
}


