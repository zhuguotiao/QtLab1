#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStack>
#include<QLabel>
#include<QKeyEvent>
#include<QMap>
#include<QPushButton>

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
    QMap<int, QPushButton*> digitBTNs;

    QString calculation(bool *ok=NULL);

private slots:
    void btnNumClicked();
    void on_btnPoint_clicked();
    void on_btnDel_clicked();
//双操作数处理函数
    void btnbinaryOperatorClicked();
//单操作数处理函数
    void btnUnaryOperatorClicked();


    void on_btnEqual_clicked();


    //增加键盘输入
    virtual void keyPressEvent(QKeyEvent *event);

    void on_btnClearAll_clicked();

    void on_btnClear_clicked();



    void on_btnMinus_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
