#include "graphicwidget.h"
#include <QMouseEvent>

GraphicWidget::GraphicWidget()
{

}

void GraphicWidget::mousePressEvent(QMouseEvent *event){
    emit circleClicked(event->x(),event->y());
}
