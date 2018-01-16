/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *showForces;
    QCheckBox *showDirection;
    QCheckBox *showWayPoints;
    QLabel *label_3;
    QDoubleSpinBox *destForceCoe;
    QLabel *label;
    QDoubleSpinBox *obstacleForceCoe;
    QLabel *label_2;
    QDoubleSpinBox *agentsForceCoe;
    QPushButton *resetCoefficientsB;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QPushButton *startStopB;
    QPushButton *restartB;
    QPushButton *loadScenarioB;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    GLWidget *myGLWidget;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        showForces = new QCheckBox(centralWidget);
        showForces->setObjectName(QStringLiteral("showForces"));

        verticalLayout->addWidget(showForces);

        showDirection = new QCheckBox(centralWidget);
        showDirection->setObjectName(QStringLiteral("showDirection"));

        verticalLayout->addWidget(showDirection);

        showWayPoints = new QCheckBox(centralWidget);
        showWayPoints->setObjectName(QStringLiteral("showWayPoints"));

        verticalLayout->addWidget(showWayPoints);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        destForceCoe = new QDoubleSpinBox(centralWidget);
        destForceCoe->setObjectName(QStringLiteral("destForceCoe"));
        destForceCoe->setWrapping(false);
        destForceCoe->setFrame(true);
        destForceCoe->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        destForceCoe->setDecimals(1);
        destForceCoe->setMaximum(10);
        destForceCoe->setSingleStep(0.1);
        destForceCoe->setValue(1);

        verticalLayout->addWidget(destForceCoe);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        obstacleForceCoe = new QDoubleSpinBox(centralWidget);
        obstacleForceCoe->setObjectName(QStringLiteral("obstacleForceCoe"));
        obstacleForceCoe->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        obstacleForceCoe->setDecimals(1);
        obstacleForceCoe->setMaximum(10);
        obstacleForceCoe->setSingleStep(0.1);
        obstacleForceCoe->setValue(1);

        verticalLayout->addWidget(obstacleForceCoe);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        agentsForceCoe = new QDoubleSpinBox(centralWidget);
        agentsForceCoe->setObjectName(QStringLiteral("agentsForceCoe"));
        agentsForceCoe->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        agentsForceCoe->setDecimals(1);
        agentsForceCoe->setMaximum(10);
        agentsForceCoe->setSingleStep(0.1);
        agentsForceCoe->setValue(1);

        verticalLayout->addWidget(agentsForceCoe);

        resetCoefficientsB = new QPushButton(centralWidget);
        resetCoefficientsB->setObjectName(QStringLiteral("resetCoefficientsB"));

        verticalLayout->addWidget(resetCoefficientsB);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setValue(30);
        horizontalSlider->setSliderPosition(30);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        horizontalSlider->setTickInterval(0);

        verticalLayout->addWidget(horizontalSlider);

        startStopB = new QPushButton(centralWidget);
        startStopB->setObjectName(QStringLiteral("startStopB"));

        verticalLayout->addWidget(startStopB);

        restartB = new QPushButton(centralWidget);
        restartB->setObjectName(QStringLiteral("restartB"));

        verticalLayout->addWidget(restartB);

        loadScenarioB = new QPushButton(centralWidget);
        loadScenarioB->setObjectName(QStringLiteral("loadScenarioB"));

        verticalLayout->addWidget(loadScenarioB);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_2);

        myGLWidget = new GLWidget(centralWidget);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(myGLWidget->sizePolicy().hasHeightForWidth());
        myGLWidget->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(myGLWidget);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(released()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Social Force Simulator", Q_NULLPTR));
        showForces->setText(QApplication::translate("MainWindow", "Show forces", Q_NULLPTR));
        showDirection->setText(QApplication::translate("MainWindow", "Show velocities", Q_NULLPTR));
        showWayPoints->setText(QApplication::translate("MainWindow", "Show waypoints", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Destination force coefficient", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Obstacle force coefficient", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Other agents' force coefficient", Q_NULLPTR));
        resetCoefficientsB->setText(QApplication::translate("MainWindow", "Reset coefficients", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Time interval", Q_NULLPTR));
        startStopB->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        restartB->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        loadScenarioB->setText(QApplication::translate("MainWindow", "Load scenario", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
