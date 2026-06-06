#include "panda_qt_gui/RobotController.hpp"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    controller_ = new RobotController();
    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout();
    j1MinusButton = new QPushButton("J1 -");
    j1PlusButton  = new QPushButton("J1 +");
    j2MinusButton = new QPushButton("J2 -");
    j2PlusButton  = new QPushButton("J2 +");
    j3MinusButton = new QPushButton("J3 -");
    j3PlusButton  = new QPushButton("J3 +");
    j4MinusButton = new QPushButton("J4 -");
    j4PlusButton  = new QPushButton("J4 +");
    j5MinusButton = new QPushButton("J5 -");
    j5PlusButton  = new QPushButton("J5 +");
    j6MinusButton = new QPushButton("J6 -");
    j6PlusButton  = new QPushButton("J6 +");
    j7MinusButton = new QPushButton("J7 -");
    j7PlusButton  = new QPushButton("J7 +");
    homeButton = new QPushButton("HOME");
    connect(homeButton, &QPushButton::clicked,
            this, &MainWindow::onHomePressed);
    connect(j1PlusButton, &QPushButton::clicked,
            this, &MainWindow::onJ1Plus);
    connect(j1MinusButton, &QPushButton::clicked,
            this, &MainWindow::onJ1Minus);
    connect(j2PlusButton, &QPushButton::clicked,
            this, &MainWindow::onJ2Plus);
    connect(j2MinusButton, &QPushButton::clicked,
            this, &MainWindow::onJ2Minus);
    connect(j3PlusButton, &QPushButton::clicked,
            this, &MainWindow::onJ3Plus);
    connect(j3MinusButton, &QPushButton::clicked,
            this, &MainWindow::onJ3Minus);
    connect(j4PlusButton, &QPushButton::clicked,
            this, &MainWindow::onJ4Plus);
    connect(j4MinusButton, &QPushButton::clicked,
            this, &MainWindow::onJ4Minus);
    connect(j5PlusButton, &QPushButton::clicked,
            this, &MainWindow::onJ5Plus);
    connect(j5MinusButton, &QPushButton::clicked,
            this, &MainWindow::onJ5Minus);
    connect(j6PlusButton, &QPushButton::clicked,
            this, &MainWindow::onJ6Plus);
    connect(j6MinusButton, &QPushButton::clicked,
            this, &MainWindow::onJ6Minus);
    connect(j7PlusButton, &QPushButton::clicked,
            this, &MainWindow::onJ7Plus);
    connect(j7MinusButton, &QPushButton::clicked,
            this, &MainWindow::onJ7Minus);
    auto addJointRow =
        [&](QPushButton *minusBtn, QPushButton *plusBtn)
        {
            auto *row = new QHBoxLayout();
            row->addWidget(minusBtn);
            row->addWidget(plusBtn);
            layout->addLayout(row);
        };
    addJointRow(j1MinusButton, j1PlusButton);
    addJointRow(j2MinusButton, j2PlusButton);
    addJointRow(j3MinusButton, j3PlusButton);
    addJointRow(j4MinusButton, j4PlusButton);
    addJointRow(j5MinusButton, j5PlusButton);
    addJointRow(j6MinusButton, j6PlusButton);
    addJointRow(j7MinusButton, j7PlusButton);
    layout->addWidget(homeButton);
    central->setLayout(layout);
    setCentralWidget(central);
    setWindowTitle("Panda Controller");
    resize(450, 500);
}
void MainWindow::onHomePressed()
{
    controller_->goHome();
}
void MainWindow::onJ1Plus()  { controller_->moveJoint(0,  0.08); }
void MainWindow::onJ1Minus() { controller_->moveJoint(0, -0.08); }

void MainWindow::onJ2Plus()  { controller_->moveJoint(1,  0.08); }
void MainWindow::onJ2Minus() { controller_->moveJoint(1, -0.08); }

void MainWindow::onJ3Plus()  { controller_->moveJoint(2,  0.08); }
void MainWindow::onJ3Minus() { controller_->moveJoint(2, -0.08); }

void MainWindow::onJ4Plus()  { controller_->moveJoint(3,  0.08); }
void MainWindow::onJ4Minus() { controller_->moveJoint(3, -0.08); }

void MainWindow::onJ5Plus()  { controller_->moveJoint(4,  0.08); }
void MainWindow::onJ5Minus() { controller_->moveJoint(4, -0.08); }

void MainWindow::onJ6Plus()  { controller_->moveJoint(5,  0.08); }
void MainWindow::onJ6Minus() { controller_->moveJoint(5, -0.08); }
void MainWindow::onJ7Plus()  { controller_->moveJoint(6,  0.08); }
void MainWindow::onJ7Minus() { controller_->moveJoint(6, -0.08); }
