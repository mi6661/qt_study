#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer;

    QImage img;
    img.load("E:\\C C++\\Qt\\Study\\Windows\\QTimer\\images\\1.png");
    ui->label->setPixmap(QPixmap::fromImage(img));

    //定时器时间到，发出timeout信号
    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);

    pic_id = 2;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_start_clicked(){
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot(){
    QString path("E:\\C C++\\Qt\\Study\\Windows\\QTimer\\images\\");
    path += QString::number(pic_id) + ".png";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));
    pic_id++;
    if(5 == pic_id) pic_id = 1;
}



void Widget::on_btn_stop_clicked()
{
    timer->stop();
}


void Widget::on_btn_single_clicked()
{
    QTimer::singleShot(1000,this,SLOT(timeoutSlot()));
}

