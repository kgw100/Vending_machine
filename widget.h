#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int ChangeMoney(int n);
    void Msg_return(int money);
    int money{0};
private slots:
    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_100_clicked();

    void on_pb_500_clicked();

    void on_coffee_clicked();

    void on_tea_clicked();

    void on_Gongcha_clicked();

    void on_Return_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
