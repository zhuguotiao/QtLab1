#include "mainwindow.h"
#include "ui_mainwindow.h"

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



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnNumClicked()
{
    QString str=qobject_cast<QPushButton*>(sender())->text();
    QString origin=ui->display->text();
    str=origin+str;
    ui->display->setText(str);
    ui->statusbar->showMessage(qobject_cast<QPushButton*>(sender())->text()+"click");
}

void MainWindow::on_btnPoint_clicked()
{
    QString str=ui->display->text();
    if(str.contains("."))
        return;
    else
        str=str+".";
    ui->display->setText(str);
}


void MainWindow::on_btnDel_clicked()
{
    QString str=ui->display->text();
    str=str.left(str.length()-1);
    ui->display->setText(str);
}

