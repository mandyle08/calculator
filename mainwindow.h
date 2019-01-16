#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double value = 0.0;
    bool addTrigger;
    bool minusTrigger;
    bool divideTrigger;
    bool multTrigger;

private slots:
    void NumButton();
    void ArithmeticButton();
    void EqualButton();
    void NegPosButton();
    void ClearButton();
};

#endif // MAINWINDOW_H
