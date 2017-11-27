#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(compute_grade()));

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::compute_grade() {

    int hw1, hw2, hw3, hw4, hw5, mdt1, mdt2, fin;

    hw1 = ui->spinBox->value();
    hw2 = ui->spinBox_2->value();
    hw3 = ui->spinBox_3->value();
    hw4 = ui->spinBox_4->value();
    hw5 = ui->spinBox_5->value();
    mdt1 = ui->spinBox_6->value();
    mdt2 = ui->spinBox_7->value();
    fin = ui->spinBox_8->value();

    int hw = hw1 + hw2 + hw3 + hw4 + hw5;

    double hw_ratio, mdt_ratio, fin_ratio;

    QString display;

    if(ui->comboBox->currentText() == "PIC10A"){
        hw_ratio = 0.15;
        fin_ratio = 0.55;
        mdt_ratio = 0.3;

        if(ui->radioButton->isChecked())
            display = QString::number(hw/5*hw_ratio + fin*fin_ratio + (mdt1+mdt2)/2*mdt_ratio);
        else if(ui->radioButton_2->isChecked())
            display = QString::number(hw/5*hw_ratio + fin*fin_ratio + std::max(mdt1,mdt2)*mdt_ratio);

        ui->lineEdit->setText(display);
    }

    else if(ui->comboBox->currentText() == "PIC10B"){
        hw_ratio = 0.25;

        if(ui->radioButton->isChecked()){
            mdt_ratio = 0.4;
            fin_ratio = 0.35;
            display = QString::number(hw/5*hw_ratio + fin*fin_ratio + (mdt1+mdt2)/2*mdt_ratio);
        }
        else if(ui->radioButton_2->isChecked()){
            mdt_ratio = 0.2;
            fin_ratio = 0.55;
            display = QString::number(hw/5*hw_ratio + fin*fin_ratio + std::max(mdt1,mdt2)*mdt_ratio);
        }

        ui->lineEdit->setText(display);
    }

}

