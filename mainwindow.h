#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString> opcodes;

    QString calculation(bool *ok=NULL);

private slots:
    void btnNumClicked();
    void on_btnPoint_clicked();
    void on_btnDel_clicked();
    void btnbinaryOperatorClicked();



    void on_btnEqual_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
