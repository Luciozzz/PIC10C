#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QString>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void compute_grade();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
