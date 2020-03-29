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
#include <QtCharts>
#include <QStringList>

class Model;
class Controller;

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model *model);
    ~View();
    void reset();
    void startSimulation(int value);
    void nextIndex(int value);
    void showResults();
    void updateMsg();
    void drawCircle();
    void enable();
    void setChart();

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
    QGraphicsEllipseItem *cercle;
    QPushButton *back;
    QPushButton *results;
    QGridLayout *resultGrid;
    QPushButton *leaveResult;
    QPushButton *restart;
    QLabel *txtMsg;
    QLineSeries *series;
    QLineSeries *fitts;
    QStringList *labels;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLabel *ecart;
    QLabel *erreur;
    QLabel *intervalle;
    QLabel *diff;

    qreal posX;
    qreal posY;
    int i = 1;
};
#endif // View_H
