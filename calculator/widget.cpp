#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置应用标题
    this->setWindowTitle("calculator");
    //设置窗体大小
    this->setMaximumSize(200,300);
    this->setMinimumSize(200,300);
    //设置字体
    QFont xfont("仿宋",14);//字体对象
    ui->edit_result->setFont(xfont);
    //按钮上放图片
    QIcon icon("E:\\C C++\\Qt\\Study\\calculator\\back.png");
    ui->btn_back->setIcon(icon);
    //改变按钮背景色
    ui->btn_equal->setStyleSheet("background:green");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_0_clicked()
{
    expression += "0";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_1_clicked()
{
    expression += "1";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_2_clicked()
{
    expression += "2";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_3_clicked()
{
    expression += "3";
    ui->edit_result->setText(expression);
}

void Widget::on_btn_4_clicked()
{
    expression += "4";
    ui->edit_result->setText(expression);
}

void Widget::on_btn_5_clicked()
{
    expression += "5";
    ui->edit_result->setText(expression);
}

void Widget::on_btn_6_clicked()
{
    expression += "6";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_7_clicked()
{
    expression += "7";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_8_clicked()
{
    expression += "8";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_9_clicked()
{
    expression += "9";
    ui->edit_result->setText(expression);
}

void Widget::on_btn_lc_clicked()
{
    expression += "(";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_rc_clicked()
{
    expression += ")";
    ui->edit_result->setText(expression);
}

void Widget::on_btn_add_clicked()
{
    //加
    expression += "+";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_sub_clicked()
{
    //减
    expression += "-";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_mul_clicked()
{
    //乘
    expression += "*";
    ui->edit_result->setText(expression);
}

void Widget::on_btn_div_clicked()
{
    //除
    expression += "/";
    ui->edit_result->setText(expression);
}


void Widget::on_btn_equal_clicked()
{
    //这里通过算法，计算字符串算式expression。得出结果。展示略去。

}


void Widget::on_btn_clear_clicked()
{
    expression.clear();
    ui->edit_result->clear();
}

void Widget::on_btn_back_clicked()
{
    //退格
    expression.chop(1);   //chop(n)从字符串尾部去除n个字符
    ui->edit_result->setText(expression);
}

