#ifndef VIEW_H
#define VIEW_H

#include "graphicwidget.h"

#include <QMainWindow>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QStackedLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QGraphicsScene>

class Model;
class Controller;

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model *model);
    ~View();
    void startSimulation(int value);
    void nextIndex(int value);
    void updateMsg();
    void drawCircle();
    void enable();

private:
    Model *model;
    Controller *controller;
    QDoubleSpinBox *aSpin;
    QDoubleSpinBox *bSpin;
    QSpinBox *lineOneSpin;
    QSpinBox *lineTwoSpin;
    QSpinBox *lineThreeSpin;
    QPushButton *leave;
    QPushButton *start;
    QStackedLayout *mainStack;
    GraphicWidget *graphicView;
    QGraphicsScene *graphScene;
    QPushButton *back;
    QPushButton *results;
    QGraphicsView *resultGraph;
    QPushButton *leaveResult;
    QPushButton *restart;
    QLabel *txtMsg;
};
#endif // View_H
