#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#define TIMEOUT 1*1000


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    //计时器触发的回调函数。只要到达指定时刻，就会触发这个函数。
    //这是一个虚函数。继承于QObject。
    virtual void timerEvent(QTimerEvent *event);
    ~Widget();

private slots:
    //开始按钮和暂停按钮的槽函数
    void on_btn_start_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    //用于切换图片的一个计时器id。计时器的唯一标识符
    int myTimerId;
    //图片id。这个只是用于拼接图片路径。也可以说是图片的唯一标识符
    int picId;
};
#endif // WIDGET_H
