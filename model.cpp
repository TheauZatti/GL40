#include "model.h"
#include "../View/view.h"

#include <QtMath>

Model::Model()
{
    this->view = new View(this);
}

void Model::compute(){
    int temp;
    temp = qSqrt(qPow((coordsTab[i].x() - x),2)+qPow((coordsTab[i].y()-y),2));
    timeCompute.push_front(a+(b*log2((temp/sizes[i])+1)));
    i++;
}

void Model::resetVal(){
    number = 10;
    min = 10;
    max = 150;
    results.clear();
    timeCompute.clear();
    a = 0.2;
    b = 0.1;
    ecartTypeVal=0;
    erreurTypeVal=0;
    intervalleVal=0;
    diffMoyenneVal=0;
    results.clear();
    sizes.clear();
    moyenne = 0;
    taille = 0;
    rayon = 0;
    coords.setX(0);
    coords.setY(0);
    distance.clear();
    coordsTab.clear();
    i = 0;
    x = 0;
    y = 0;
}

void Model::ecartType(){
    int temp = 0;
    for(int i=0;i<results.length();i++){
        temp += results[i];
    }
    moyenne = temp/results.length();

    int temp2 = 0;
    for(int j=0;j<results.length();j++){
        temp2 += qPow((results[j]-moyenne),2);
    }

    ecartTypeVal = qSqrt(temp2/results.length());

}

void Model::erreurType(){

    erreurTypeVal = ecartTypeVal/qSqrt(results.length());
}

void Model::intervalle(){
    intervalleVal = moyenne + (0.95*erreurTypeVal);
}

void Model::diffMoyenne(){

    int temp = 0;
    for(int i=0;i<results.length();i++){
        temp += abs(results[i]-moyenne);
    }

    diffMoyenneVal = temp/results.length();
}

double Model::maximum(){
    maxVal = results.first();

    for(int i=1;i<results.length();i++){
        if(maxVal<results[i]){
            maxVal = results[i];
        }
    }
    return maxVal;
}
