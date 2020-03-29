#ifndef MODEL_H
#define MODEL_H

#include <QPoint>
#include <QList>

class View;
class Controller;

class Model
{
public:
    Model();
    void compute();
    void resetVal();
    void ecartType();
    void erreurType();
    void diffMoyenne();
    void intervalle();
    double maximum();

private:
    View *view;
    int i = 0;
    double a = 0.20;
    double b = 0.10;
    int number = 10;
    int min = 10;
    int max = 150;
    double maxVal;
    int moyenne;
    double ecartTypeVal = 0;
    double erreurTypeVal = 0;
    double diffMoyenneVal = 0;
    double intervalleVal = 0;
    int rayon;
    int taille;
    int gWidth = 600;
    int gHeight = 200;

    QPoint coords;
    QList<double> timeCompute;
    QList<double> results;
    QList<int> sizes;
    QList<double> distance;
    QList<QPoint> coordsTab;

    int x,y;

    friend View;
    friend Controller;
};

#endif // MODEL_H
