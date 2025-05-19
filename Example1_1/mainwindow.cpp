#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //连接信号与槽 谁发出信号 发出什么信息号 谁处理信号 怎么处理信号
    connect(ui->cmdLineEdit,&QLineEdit::returnPressed,this,&MainWindow::on_cmdbtn_clicked);
    connect(ui->cancelbtn,&QPushButton::clicked,this,&MainWindow::on_cancelbtn_clicked);
    connect(ui->browsebtn,&QPushButton::clicked,[this](){
        QMessageBox::information(this,"信息","点击浏览");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmdbtn_clicked()
{
    //获取lineEdit数据
    QString program = ui->cmdLineEdit->text();

    //输出提示
    std::cout<<"cmdbtn was clicked!!"<<std::endl;
    //获取启动程序的对象
    QProcess *myProcess = new QProcess;
    //启动进程
    myProcess->start(program);
}

void MainWindow::on_cancelbtn_clicked(){
    this->close();
}


