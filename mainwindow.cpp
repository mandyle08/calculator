#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");
    ui->Display->setText(QString::number(value));

    QPushButton *numButton[10];

    for(int i = 0; i < 10; i++){
        QString buttonName = "Button" + QString::number(i);
       numButton[i] = MainWindow::findChild <QPushButton *> (buttonName);
       connect(numButton[i], SIGNAL(released()), this, SLOT(NumButton()));
    }
    connect(ui->ButtonAdd, SIGNAL(released()),this, SLOT(ArithmeticButton()));
    connect(ui->ButtonMinus, SIGNAL(released()), this, SLOT(ArithmeticButton()));
    connect(ui->ButtonMultiply, SIGNAL(released()),this, SLOT(ArithmeticButton()));
    connect(ui->ButtonDivide, SIGNAL(released()),this, SLOT(ArithmeticButton()));
    connect(ui->ButtonEqual, SIGNAL(released()), this, SLOT(EqualButton()));
    connect(ui->ButtonAC, SIGNAL(released()), this, SLOT(ClearButton()));
    connect(ui->ButtonNegPos, SIGNAL(released()), this, SLOT(NegPosButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumButton()
{
    QPushButton *button =qobject_cast <QPushButton *>(sender());
    QString buttonValue = button->text();
    QString displayValue = ui->Display->text();

    if((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0.0)){
        ui->Display->setText(buttonValue);
    }else {
        QString newValue = displayValue + buttonValue;
        double dblValue = newValue.toDouble();
        ui->Display->setText(QString::number(dblValue));
    }
}

void MainWindow::ArithmeticButton()
{
    addTrigger = false;
    minusTrigger = false;
    divideTrigger = false;
    multTrigger = false;

    QString displayValue = ui->Display->text();
    value = displayValue.toDouble();

    QPushButton *button = qobject_cast <QPushButton *>(sender());
    QString buttonValue = button->text();

    if(QString::compare(buttonValue, "+") == 0){
        addTrigger = true;
    }else if(QString::compare(buttonValue, "-") == 0){
        minusTrigger = true;
    }else if(QString::compare(buttonValue, "/") == 0){
        divideTrigger = true;
   } else if(QString::compare(buttonValue, "x") == 0){
        multTrigger = true;

    }


    ui->Display->setText(buttonValue);
}

void MainWindow::EqualButton()
{
    double sum = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    if(addTrigger || minusTrigger || divideTrigger || multTrigger){

        if(addTrigger){
            sum = value + dblDisplayVal;
            addTrigger = false;
        }else if(minusTrigger){
            sum = value - dblDisplayVal;
            minusTrigger = false;
        }else if(divideTrigger){
            sum = value / dblDisplayVal;
            divideTrigger = false;
        }else if(multTrigger){
            sum = value * dblDisplayVal;
            multTrigger = false;
        }
    }

    ui->Display->setText(QString::number(sum));
}

void MainWindow::NegPosButton()
{
    QString displayValue = ui->Display->text();
    double dbleDisplayValue = displayValue.toDouble();
    dbleDisplayValue = -1*dbleDisplayValue;

    ui->Display->setText(QString::number(dbleDisplayValue));
}

void MainWindow::ClearButton()
{
    value = 0.0;
    ui->Display->setText(QString::number(0));

}
