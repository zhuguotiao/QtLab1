#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include"math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    //绑定加减乘除的双操作数
    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnbinaryOperatorClicked()));
    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(btnbinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnbinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnbinaryOperatorClicked()));

    //绑定单操作数
    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnsqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result=0;
    if(operands.size()==2&&opcodes.size()>0){
        //去操作数
        double operand1=operands.front().toDouble();
        operands.pop_front();
        double operand2=operands.front().toDouble();
        operands.pop_front();

        //取操作符
        QString op=opcodes.front();
        opcodes.pop_front();
        if(op=="+"){
            result=operand1+operand2;
        }else if(op=="-"){
            result=operand1-operand2;
        }else if(op=="*"){
            result=operand1*operand2;
        }else if(op=="/"){
            result=operand1/operand2;
        }
        operands.push_back(QString::number(result));

        ui->statusbar->showMessage("这是计算函数:"+QString("operands is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));
    }else{
        ui->statusbar->showMessage(QString("operands is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));
    }
    return QString::number(result);
}



void MainWindow::btnNumClicked()
{
    QString digit=qobject_cast<QPushButton*>(sender())->text();
    if(digit=="0" && operand=="0")
        digit="";
    if(digit!="0" && operand=="0")
        operand="";
    operand +=digit;
    ui->display->setText(operand);

}

void MainWindow::on_btnPoint_clicked()
{
    QString digit=ui->display->text();
    if(operand.contains("."))
        return;
    else
        operand+=".";
    ui->display->setText(operand);
}


void MainWindow::on_btnDel_clicked()
{
    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
}

void MainWindow::btnbinaryOperatorClicked()
{
    QString opcode=qobject_cast<QPushButton*>(sender())->text();
    if(operand != ""){
        operands.push_back(operand);
        operand="";
        opcodes.push_back(opcode);
    }

    QString result=calculation();
    ui->display->setText(result);

}

void MainWindow::btnUnaryOperatorClicked()
{
    if(operand != ""){
        double result = operand.toDouble();
        operand="";
        QString op=qobject_cast<QPushButton*>(sender())->text();

        if(op=="%")
            result /=100.0;
        else if(op =="1/x")
            result=1/result;
        else if(op=="x^2")
            result*=result;
        else if(op=="√")
            result=sqrt(result);

        ui->display->setText(QString::number(result));
    }
}


void MainWindow::on_btnEqual_clicked()
{
    if(operand != ""){
        operands.push_back(operand);
        operand="";
    }

    QString result=calculation();
    ui->display->setText(result);

}

