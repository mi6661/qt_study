#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>


//QT的命名空间宏，用于防止名字冲突
QT_BEGIN_NAMESPACE
//建立一个Ui命名空间。命名空间中有下面定义的类。
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//创建一个基础鱼QMainWindow的类
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //构造函数
    MainWindow(QWidget *parent = nullptr);
    //析构函数
    ~MainWindow();

/*Qt的核心机制之一槽，用来响应信号。
*
*这处理响应信号是，如果connect使用旧版本方法，需要使用SLOT()来引入查函数
*不仅有private slots，也有public、protected。
*
*如果使用的是旧版的SIGNAL(),SLOT()。则必须将槽函数写在这些地方。如果使用
*C++11的新语法（函数指针方式），这不需要。
*
*/
private slots:
    void on_cmdbtn_clicked();
    void on_cancelbtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
