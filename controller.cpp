#include "controller.h"

#include "../Model/model.h"
#include "../View/view.h"

#include <QApplication>
#include <QDebug>
#include <QtMath>
#include <QtGlobal>

Controller::Controller(View *view, Model *model)
{
    this->view = view;
    this->model = model;
    this->start();
}

void Controller::quit(){
    QApplication::quit();
}

void Controller::start(){
    this->view->show();
}

void Controller::startSimulation(){
    /*qDebug() << this->model->a;
    qDebug() << this->model->b;
    qDebug() << this->model->number;
    qDebug() << this->model->min;
    qDebug() << this->model->max;*/
    this->view->startSimulation(1);
}

void Controller::aChanged(double a){
    this->model->a = a;
}

void Controller::bChanged(double b){
    this->model->b = b;
}

void Controller::numberChanged(int nbr){
    this->model->number = nbr;
}

void Controller::minChanged(int min){
    this->model->min = min;
}

void Controller::maxChanged(int max){
    this->model->max = max;
}

void Controller::back(){
    this->view->nextIndex(0);
}

void Controller::results(){
    this->view->nextIndex(2);
}

void Controller::restart(){
    this->view->nextIndex(0);
}

void Controller::clicked(int x,int y ){

    if(this->model->number>0){
        qDebug() <<this->model->coords->x() << x;
        if(qSqrt(qPow((this->model->coords->x()-x),2)+qPow((this->model->coords->y()-y),2)) <= (this->model->rayon)){
            this->model->number -= 1;
            this->view->updateMsg();
            this->view->drawCircle();
        }
    }else{
        this->view->enable();
    }
}
