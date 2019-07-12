#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ChangeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}


int Widget::ChangeMoney(int n){
    money += n;


    ui->lcdnumber->display(QString::number(money));


    if(money < 100)
    {
        ui->coffee->setEnabled(false);
        ui->Gongcha->setEnabled(false);
        ui->tea->setEnabled(false);
    }
    else if(100<= money && money<150)
    {
        ui->coffee->setEnabled(true);
        ui->Gongcha->setEnabled(false);
        ui->tea->setEnabled(false);
    }
    else if (150<= money && money <200 )
    {
        ui->coffee->setEnabled(true);
        ui->tea->setEnabled(true);
        ui->Gongcha->setEnabled(false);
    }
    else {
        ui->coffee->setEnabled(true);
        ui->Gongcha->setEnabled(true);
        ui->tea->setEnabled(true);

    }
    return money;
}
void Widget::Msg_return(int money)
{
            QMessageBox msg;
            int m10;
            int m50;
            int m100;
            int m500;

      m500 = money / 500;
      m100 = (money-500*m500) / 100;
      m50  = (money-500*m500-100*m100) / 50;
      m10  = (money-500*m500-100*m100-50*m50)/10;
      if(m10 == 0 && m50 == 0 && m100 ==0 && m500==0)
      {
           msg.information(nullptr, "Total","No money");
      }
      else{
      msg.information(nullptr, "Total",QString("10:%1 50: %2 100: %3 500:%4").arg(m10).arg(m50).arg(m100).arg(m500));
      }

}
void Widget::on_pb_10_clicked()
{
   ChangeMoney(10);

}

void Widget::on_pb_50_clicked()
{
    ChangeMoney(50);
}

void Widget::on_pb_100_clicked()
{
   ChangeMoney(100);
}

void Widget::on_pb_500_clicked()
{
    ChangeMoney(500);
}

void Widget::on_coffee_clicked()
{
    ChangeMoney(-100);
}

void Widget::on_tea_clicked()
{
    ChangeMoney(-150);
}

void Widget::on_Gongcha_clicked()
{
    ChangeMoney(-200);
}


void Widget::on_Return_clicked()
{
  Msg_return( ChangeMoney(0));
}
