#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->btn_start,&QPushButton::clicked,this,&Widget::btn_start);
    // this->paths[0] = "./images/1.png";
    // this->paths[1] = "./images/2.png";
    // this->paths[2] = "./images/3.png";
    // this->paths[3] = "./images/4.png";

    this->pic_index = 0;

    //ui->label->setText(this->paths[this->pic_index]);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::btn_start(){
    //启动计时器
    timerId = this->startTimer(TIMEOUT);
}

void Widget::on_btn_stop_clicked()
{
    //暂停计时器
    this->killTimer(timerId);
}
void Widget::timerEvent(QTimerEvent *event){
    if(event->timerId() == timerId){
        this->pic_index++;
        //this->ui->label->setText(this->paths[this->pic_index]);
    }
}
