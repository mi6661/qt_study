#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    picId = 2;

    //QPixmap 是一个图片对象。参数树图片的绝对路径。
    QPixmap pix("E:\\C C++\\Qt\\Study\\objectTimer\\1.png");
    //通过TextLabel下个setPixmap设置图片。参数是一个QPixmap对象。
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}

//开始按钮的槽函数
void Widget::on_btn_start_clicked()
{
    //启动定时器,返回定时器的编号
    //继承于QObject的启动计时器的函数。参数是计时时长。
    myTimerId = this->startTimer(TIMEOUT);
}

//暂停按钮的槽函数
void Widget::on_pushButton_2_clicked()
{
    //继承于QObject的暂停计时器的函数。参数是计时器id。
    this->killTimer(myTimerId);
}

//计时器触发是的回调函数。
void Widget::timerEvent(QTimerEvent *event){
    if(event->timerId() != myTimerId) return;
    QString path("E:\\C C++\\Qt\\Study\\objectTimer\\");
    path += QString::number(picId);
    path += ".png";
    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picId++;
    if(5==picId) picId = 1;
}


