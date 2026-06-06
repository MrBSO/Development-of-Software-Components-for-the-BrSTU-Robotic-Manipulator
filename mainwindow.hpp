#pragma once
#include <QMainWindow>
class QPushButton;
class RobotController;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private slots:
    void onHomePressed();
    void onJ1Plus();
    void onJ1Minus();
    void onJ2Plus();
    void onJ2Minus();
    void onJ3Plus();
    void onJ3Minus();
    void onJ4Plus();
    void onJ4Minus();
    void onJ5Plus();
    void onJ5Minus();
    void onJ6Plus();
    void onJ6Minus();
    void onJ7Plus();
    void onJ7Minus();
private:
    QPushButton *homeButton;
    QPushButton *j1PlusButton;
    QPushButton *j1MinusButton;
    QPushButton *j2PlusButton;
    QPushButton *j2MinusButton;
    QPushButton *j3PlusButton;
    QPushButton *j3MinusButton;
    QPushButton *j4PlusButton;
    QPushButton *j4MinusButton;
    QPushButton *j5PlusButton;
    QPushButton *j5MinusButton;
    QPushButton *j6PlusButton;
    QPushButton *j6MinusButton;
    QPushButton *j7PlusButton;
    QPushButton *j7MinusButton;
    RobotController *controller_;
};
