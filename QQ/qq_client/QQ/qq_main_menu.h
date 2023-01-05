#ifndef QQ_MAIN_MENU_H
#define QQ_MAIN_MENU_H

#include <QWidget>
#include"internet.h"
#include<QTimerEvent>
#include<QDebug>
#include<QIntValidator>
#include<QRegExpValidator>
#include<QMovie>
#include"qq_list.h"
QT_BEGIN_NAMESPACE
namespace Ui { class qq_main_menu; }
QT_END_NAMESPACE

class qq_main_menu : public QWidget
{
    Q_OBJECT

public:
    qq_main_menu(QWidget *parent = nullptr);
    ~qq_main_menu();
    internet *client;


    int timerId;
    void connect_server();
protected:
    void timerEvent(QTimerEvent* event);
    void closeEvent(QCloseEvent *event);

private slots:

    void on_Button_exit_clicked();

    void on_Button_register_clicked();

    void on_Button_back_login_clicked();

    void on_Button_ewm2_clicked();

    void on_Button_ewm_clicked();

    void on_Button_go_clicked();

    void on_Button_register_go_clicked();

    void on_Button_cancel_clicked();


    void on_Button_CG_ip_clicked();

    void on_Button_CG_back_clicked();

    void on_Button_CG_mr_clicked();

    void on_Button_set_clicked();

private:
    Ui::qq_main_menu *ui;
};
#endif // QQ_MAIN_MENU_H
