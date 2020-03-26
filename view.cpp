#include "view.h"
#include "../Model/model.h"
#include "../Controller/controller.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QImage>
#include <QStackedLayout>
#include <QGraphicsView>
#include <QDebug>


View::View(Model *model): QMainWindow()
{
    qsrand(time(NULL));

    this->model = model;
    this->controller = new Controller(this,this->model);

    this->setFixedSize(800,600);
    QWidget *main = new QWidget();
    this->setCentralWidget(main);

    QVBoxLayout *mainVerticalLayout = new QVBoxLayout(main);

    mainStack = new QStackedLayout;
    mainVerticalLayout->addLayout(mainStack);

    QWidget *settingsWidget = new QWidget;
    mainStack->addWidget(settingsWidget);

    QVBoxLayout *settingsVerticalLayout = new QVBoxLayout(settingsWidget);

                    /* Title */

    QHBoxLayout *titleLayout = new QHBoxLayout();
    settingsVerticalLayout->addLayout(titleLayout);
    QLabel *title = new QLabel("Programme pour vérifier le loi de Fitts");
    titleLayout->addWidget(title);
    titleLayout->setAlignment(Qt::AlignTop);
    title->setAlignment(Qt::AlignHCenter);
    QFont titleFont = title->font();
    titleFont.setPointSize(16);
    title->setFont(titleFont);

                    /*------*/

                   /*Reminder*/

    QHBoxLayout *reminderLayout = new QHBoxLayout();
    settingsVerticalLayout->addLayout(reminderLayout);
    QGroupBox *reminderBox = new QGroupBox("Rappel");
    reminderLayout->addWidget(reminderBox);
    QHBoxLayout *reminderBoxLayout = new QHBoxLayout(reminderBox);

    QVBoxLayout *reminderColumnOne = new QVBoxLayout();
    QLabel *columnOneTitle = new QLabel("Formule utilisée :");
    reminderColumnOne->addWidget(columnOneTitle);
    QLabel *image = new QLabel();
    image->setPixmap(QPixmap("C:/Users/theau/Desktop/UTBM/INFO2/GL40/TP/TP2/Formule.PNG"));
    reminderColumnOne->addWidget(image);

    QVBoxLayout *reminderColumnTwo = new QVBoxLayout();
    QLabel *columnTwoTitle = new QLabel("Choix de a et b :");
    columnTwoTitle->setAlignment(Qt::AlignTop);
    reminderColumnTwo->setAlignment(Qt::AlignHCenter);
    reminderColumnTwo->addWidget(columnTwoTitle);

    QHBoxLayout *a = new QHBoxLayout();
    QLabel *aLabel = new QLabel("Variable a :");
    a->addWidget(aLabel);
    aSpin = new QDoubleSpinBox();
    aSpin->setValue(this->model->a);
    aSpin->setFixedSize(50,20);
    a->setAlignment(Qt::AlignVCenter);
    a->addWidget(aSpin);

    QHBoxLayout *b = new QHBoxLayout();
    QLabel *bLabel = new QLabel("Variable b :");
    b->addWidget(bLabel);
    bSpin = new QDoubleSpinBox();
    bSpin->setValue(this->model->b);
    bSpin->setFixedSize(50,20);
    b->setAlignment(Qt::AlignVCenter);
    b->addWidget(bSpin);

    reminderColumnTwo->addLayout(a);
    reminderColumnTwo->addLayout(b);

    reminderBoxLayout->addLayout(reminderColumnOne);
    reminderBoxLayout->addLayout(reminderColumnTwo);

    reminderLayout->setContentsMargins(30,30,30,0);

                   /*-------*/

                   /*Config*/
    QHBoxLayout *configLayout = new QHBoxLayout();
    settingsVerticalLayout->addLayout(configLayout);
    QGroupBox *configBox = new QGroupBox("Configuration du test");
    configLayout->addWidget(configBox);
    QVBoxLayout *configBoxLayout = new QVBoxLayout(configBox);

    QHBoxLayout *lineOne = new QHBoxLayout();
    QLabel *lineOneText = new QLabel("Nombre de cibles :");
    lineOne->addWidget(lineOneText);
    lineOneSpin = new QSpinBox();
    lineOneSpin->setValue(this->model->number);
    lineOneSpin->setFixedSize(50,20);
    lineOne->setContentsMargins(10,10,10,10);
    lineOne->addWidget(lineOneSpin);

    QHBoxLayout *lineTwo = new QHBoxLayout();
    QLabel *lineTwoText = new QLabel("Taille minimum cible :");
    lineTwo->addWidget(lineTwoText);
    lineTwoSpin = new QSpinBox();
    lineTwoSpin->setValue(this->model->min);
    lineTwoSpin->setFixedSize(50,20);
    lineTwo->setContentsMargins(10,10,10,10);
    lineTwo->addWidget(lineTwoSpin);

    QHBoxLayout *lineThree = new QHBoxLayout();
    QLabel *lineThreeText = new QLabel("Taille maximum cible :");
    lineThree->addWidget(lineThreeText);
    lineThreeSpin = new QSpinBox();
    lineThreeSpin->setMaximum(200);
    lineThreeSpin->setValue(this->model->max);
    lineThreeSpin->setFixedSize(50,20);
    lineThree->setContentsMargins(10,10,10,10);
    lineThree->addWidget(lineThreeSpin);

    configBoxLayout->addLayout(lineOne);
    configBoxLayout->addLayout(lineTwo);
    configBoxLayout->addLayout(lineThree);

    configLayout->setAlignment(Qt::AlignHCenter);
    configLayout->setContentsMargins(0,20,0,20);

                    /*------*/


                    /*Button*/

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    settingsVerticalLayout->addLayout(buttonLayout);
    leave = new QPushButton("Quitter");
    start = new QPushButton("Démarer");
    buttonLayout->addWidget(leave);
    buttonLayout->addWidget(start);
    buttonLayout->setContentsMargins(60,30,60,30);

                    /*------*/

                  /*test Widget*/

    QWidget *testWidget = new QWidget;
    mainStack->addWidget(testWidget);

    QVBoxLayout *testVerticalLayout = new QVBoxLayout(testWidget);
    testVerticalLayout->setAlignment(Qt::AlignHCenter);

    testVerticalLayout->addWidget(txtMsg = new QLabel);
    this->updateMsg();

    graphicView = new GraphicWidget();
    graphicView->setFixedSize(700,300);
    testVerticalLayout->addWidget(graphicView);

    testVerticalLayout->addWidget(new QLabel("Cliquez sur les cibles qui apparaissent en <font color='red'><strong>rouge</strong></font>."));

    QHBoxLayout *testBtnLayout = new QHBoxLayout;
    back = new QPushButton("Retour");
    results = new QPushButton("Résultats");
    results->setEnabled(false);
    testBtnLayout->addWidget(back);
    testBtnLayout->addWidget(results);
    testBtnLayout->setContentsMargins(10,10,10,30);
    testVerticalLayout->addLayout(testBtnLayout);

                   /*--------------*/

                   /*result widget*/

    QWidget *resultWidget = new QWidget;
    mainStack->addWidget(resultWidget);

    QVBoxLayout *resultVerticallayout = new QVBoxLayout(resultWidget);
    resultVerticallayout->setAlignment(Qt::AlignHCenter);

    resultGraph = new QGraphicsView;
    resultGraph->setFixedSize(700,300);
    resultVerticallayout->addWidget(resultGraph);

    QGroupBox *resultsBox = new QGroupBox("Résultats");
    QGridLayout *resultGrid = new QGridLayout(resultsBox);
    resultGrid->addWidget(new QLabel("Ecart-type: " + QString::number(this->model->eccartType)),0,0);
    resultGrid->addWidget(new QLabel("Erreur type: " + QString::number(this->model->erreurType)),1,0);
    resultGrid->addWidget(new QLabel("Différence moyenne: " + QString::number(this->model->diffMoyenne)),0,1);
    resultGrid->addWidget(new QLabel("Intervalle de confiance à 95%: " + QString::number(this->model->intervalle)),1,1);

    resultVerticallayout->addWidget(resultsBox);

    QHBoxLayout *resultBtnLayout = new QHBoxLayout;
    leaveResult = new QPushButton("Quitter");
    restart = new QPushButton("Recommencer");
    resultBtnLayout->addWidget(leaveResult);
    resultBtnLayout->addWidget(restart);
    resultBtnLayout->setContentsMargins(10,20,10,20);
    resultVerticallayout->addLayout(resultBtnLayout);


                   /*-------------*/

                    /*connect*/

    connect(leave,SIGNAL(clicked()), controller, SLOT(quit()));
    connect(start,SIGNAL(clicked()), controller, SLOT(startSimulation()));
    connect(aSpin,SIGNAL(valueChanged(double)), controller, SLOT(aChanged(double)));
    connect(bSpin,SIGNAL(valueChanged(double)), controller, SLOT(bChanged(double)));
    connect(lineOneSpin,SIGNAL(valueChanged(int)), controller, SLOT(numberChanged(int)));
    connect(lineTwoSpin,SIGNAL(valueChanged(int)), controller, SLOT(minChanged(int)));
    connect(lineThreeSpin,SIGNAL(valueChanged(int)), controller, SLOT(maxChanged(int)));
    connect(back,SIGNAL(clicked()), controller, SLOT(back()));
    connect(results,SIGNAL(clicked()), controller, SLOT(results()));
    connect(leaveResult,SIGNAL(clicked()), controller, SLOT(quit()));
    connect(restart,SIGNAL(clicked()), controller, SLOT(restart()));
    connect(graphicView,SIGNAL(circleClicked(int,int)),controller,SLOT(clicked(int,int)));

                    /*-------*/

}

void View::drawCircle(){
    graphScene->clear();

    this->model->taille = (qrand() % ((this->model->max - this->model->min) + this->model->min));
    this->model->rayon = this->model->taille/2;
    qreal posX = qrand() % ((this->model->gWidth - this->model->taille) + this->model->taille );
    qreal posY = qrand() % ((this->model->gHeight - this->model->taille) + this->model->taille );

    this->model->coords = new QPoint(posX,posY);

    graphScene->addEllipse(posX,posY,this->model->taille,this->model->taille,QPen(QColor("red")),QBrush(QColor("red")));
}

void View::startSimulation(int value){
    mainStack->setCurrentIndex(value);
    this->updateMsg();
    graphScene = new QGraphicsScene;
    graphicView->setScene(graphScene);
    graphScene->clear();
    this->model->coords = new QPoint(350,150);
    this->model->rayon = 50;
    graphScene->addEllipse(325,125,100,100,QPen(QColor("blue")),QBrush(QColor("blue")));
}

void View::nextIndex(int value){
    mainStack->setCurrentIndex(value);
}

void View::updateMsg(){
    txtMsg->setText("<strong> Le Test commencera après avoir appuyer sur la cible bleu. </strong> Nombre de cibles restantes :" + QString::number(this->model->number));
}

void View::enable(){
    results->setEnabled(true);
}

View::~View()
{

}

