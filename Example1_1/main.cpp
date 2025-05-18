#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    printf("Hello Wrold");


    QPushButton *btn_test = new QPushButton;
    btn_test->setText("hello world");
    QHBoxLayout *main_layout = new QHBoxLayout;
    main_layout->addWidget(btn_test);

    w.setLayout(main_layout);

    w.show();
    return a.exec();
}
