#include "controller.h"

#include "../Model/model.h"
#include "../View/view.h"

#include <QApplication>
#include <QDebug>
#include <QtMath>
#include <QtGlobal>
#include <QList>
#include <QPoint>

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
    isActive = false;
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
    this->view->setChart();
    this->model->ecartType();
    this->model->erreurType();
    this->model->diffMoyenne();
    this->model->intervalle();
    this->view->showResults();

}

void Controller::restart(){
    this->view->nextIndex(0);
    this->model->resetVal();
    this->view->reset();
}

void Controller::clicked(int x,int y ){

    if(this->model->number>=0){
        if(qSqrt(qPow((this->model->coords.x()-x),2)+qPow((this->model->coords.y()-y),2)) <= (this->model->rayon)){
            if(isActive == true){
                if(this->model->number==0){
                    this->model->results.push_front(timer.elapsed());
                    this->model->coordsTab.push_front(this->model->coords);
                    this->model->compute();
                    this->view->enable();
                }else{
                    this->model->results.push_front(timer.elapsed());
                    this->model->coordsTab.push_front(this->model->coords);
                    this->model->compute();
                    this->model->x = x;
                    this->model->y = y;
                    this->model->number -= 1;
                    this->view->updateMsg();
                    this->view->drawCircle();
                }
            }else{
                timer.restart();
                isActive = true;
                this->model->x = x;
                this->model->y = y;
                this->model->number -= 1;
                this->view->updateMsg();
                this->view->drawCircle();
            }
        }
    }
}
