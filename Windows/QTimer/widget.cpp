#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //获取一个QTimer定时器对象
    timer = new QTimer;
    //获取一个QImage图片对象。
    QImage img;
    //图片对象载入图片。通过图片路径载入
    img.load("E:\\C C++\\Qt\\Study\\Windows\\QTimer\\images\\1.png");
    //ui界面是设置图片对象。这里依旧使用setPixmap，而参数通过QPixmap的静态方法fromImage进行转换
    ui->label->setPixmap(QPixmap::fromImage(img));

    //定时器时间到，发出timeout信号
    //将信号有槽函数链接
    /*
     *param：1.谁发出新型号；2.发出什么信号；3.谁处理信号；4.如何处理信号
     */
    connect(timer,&QTimer::timeout,this,&Widget::timeoutSlot);
    //图片的标识
    pic_id = 2;
}

Widget::~Widget()
{
    delete ui;
}

//开始按钮槽函数
void Widget::on_btn_start_clicked(){
    timer->start(TIMEOUT);
}

//定时器信号处理函数
void Widget::timeoutSlot(){
    QString path("E:\\C C++\\Qt\\Study\\Windows\\QTimer\\images\\");
    path += QString::number(pic_id) + ".png";

    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));
    pic_id++;
    if(5 == pic_id) pic_id = 1;
}


//暂停按钮槽函数
void Widget::on_btn_stop_clicked()
{
    //通过定时器对象的stop方法，暂停计时器。
    timer->stop();
}


void Widget::on_btn_single_clicked()
{
    //通过QTimer类中的静态方法singleShot设置单次计时器。
    //param:1.定时时长；2.信号处理对象；3.信号处理方法；
    QTimer::singleShot(1000,this,SLOT(timeoutSlot()));
}

