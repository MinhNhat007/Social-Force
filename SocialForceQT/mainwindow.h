#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {

class MainWindow;
}

/**
 * @brief The MainWindow class managing Qt application window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

    void on_showForces_clicked(bool checked);

    void on_showDirection_clicked(bool checked);

    void on_showWayPoints_clicked(bool checked);

    void on_destForceCoe_valueChanged(double arg1);

    void on_obstacleForceCoe_valueChanged(double arg1);

    void on_agentsForceCoe_valueChanged(double arg1);


    void on_loadScenarioB_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_restartB_clicked();

    void on_startStopB_clicked();

    void on_resetCoefficientsB_clicked();

private:
    Ui::MainWindow *ui;
    void initSocialForceCoefficients();
};

#endif // MAINWINDOW_H
