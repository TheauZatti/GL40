#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMouseEvent>

class View;
class Model;
class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(View *view, Model *model);
    void start();

private slots:
    void quit();
    void startSimulation();
    void aChanged(double a);
    void bChanged(double b);
    void numberChanged(int nbr);
    void minChanged(int min);
    void maxChanged(int max);
    void back();
    void results();
    void restart();
    void clicked(int x ,int y);

private:
    View *view;
    Model *model;
};

#endif // CONTROLLER_H
