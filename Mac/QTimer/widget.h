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
    virtual void timerEvent(QTimerEvent *event);
    ~Widget();



private slots:
    void on_btn_stop_clicked();

private:
    int timerId;
    QString paths[4];
    int pic_index;
    Ui::Widget *ui;
    void btn_start();
};
#endif // WIDGET_H
