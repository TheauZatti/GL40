#ifndef MODEL_H
#define MODEL_H

#include <QPoint>

class View;
class Controller;

class Model
{
public:
    Model();

private:
    View *view;
    double a = 0.20;
    double b = 0.10;
    int number = 10;
    int min = 10;
    int max = 150;
    double eccartType = 0;
    double erreurType = 0;
    double diffMoyenne = 0;
    double intervalle = 0;
    int rayon;
    int taille;
    int gWidth = 600;
    int gHeight = 250;
    QPoint *coords;


    friend View;
    friend Controller;
};

#endif // MODEL_H
