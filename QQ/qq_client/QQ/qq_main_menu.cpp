#include "qq_main_menu.h"
#include "ui_qq_main_menu.h"
unsigned WINAPI connect_thread(void *arg);
unsigned WINAPI please_wait(void *arg);
//bool waitstat=false;
extern int ret;
qq_main_menu::qq_main_menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qq_main_menu)
{

    ui->setupUi(this);
    ui->main_stacked_widget->setCurrentIndex(0);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    client=new internet();
    timerId=startTimer(500);

/*设置文本框的输入规则*/
    QRegExp regx_pw("[a-zA-Z0-9_.+-*/]+$");
    QRegExp regx_lg("[a-zA-Z0-9]+$");
    QValidator *validator_pw = new QRegExpValidator(regx_pw, ui->LE_passwd );
    QValidator *validator_lg=new QRegExpValidator(regx_lg,ui->LE_login);
    ui->LE_login->setValidator( validator_lg );
    ui->LE_login2->setValidator(validator_lg);
    ui->LE_passwd->setValidator(validator_pw);
    ui->LE_passwd2->setValidator(validator_pw);

    ui->LE_passwd->setEchoMode(QLineEdit::Password);//文本显示模式为密码圆圈
    ui->LE_passwd2->setEchoMode(QLineEdit::Password);
    ui->Label_server_go->setStyleSheet("QLabel{""color:blue;""}");//等待服务器回应字体变蓝
/*播放gif*/
    QMovie *mov=new QMovie(":/new/prefix1/res/please_wait.gif");
    ui->Label_please_wait->setMovie(mov);
    ui->Label_please_wait->setScaledContents(true);
    mov->start();

    ui->Label_login_stat->setStyleSheet("QLabel{""color:red;""}");
    ui->Button_register->setFlat(true);//注册按钮背景透明
    ui->Button_register->setStyleSheet("QPushButton:hover{color:blue}");//注册按钮悬停字体变蓝
    ui->Button_go->setStyleSheet("QPushButton:hover{color:blue}");//登录按钮悬停字体变蓝
    ui->LE_passwd->setStyleSheet(("QLineEdit{border-width:0;border-style:outset}"));//文本框无边框
    ui->LE_login->setStyleSheet(("QLineEdit{border-width:0;border-style:outset}"));//文本框无边框
    ui->LE_login->setPlaceholderText("账号/邮箱/手机");//文本框空提示
    ui->LE_passwd->setPlaceholderText("密码");//文本框空提示

}

qq_main_menu::~qq_main_menu()
{
    qDebug()<<"触发主界面析构函数啦"<<endl;
    delete ui;
}

void qq_main_menu::connect_server()
{
    if(client->connecting())
        return ;
    HANDLE thread=(HANDLE)_beginthreadex(NULL,0,connect_thread,(void*)client,0,NULL);
}
unsigned WINAPI connect_thread(void *arg)
{
    internet *client=(internet*)arg;
    qDebug()<<"thread_start"<<endl;
    client->connect();
    qDebug()<<"thread_over"<<endl;
}

void qq_main_menu::timerEvent(QTimerEvent *event)
{
    if(client->connect_thread_running)
    {
          ui->Label_netstat->setStyleSheet("QLabel{""color:red;""}");
          ui->Label_netstat->setText("<正在连接服务器...>");
          ui->Label_netstat2->setStyleSheet("QLabel{""color:red;""}");
          ui->Label_netstat2->setText("<正在连接服务器...>");
          return;
    }
    else if(client->connecting())
    {
        ui->Label_netstat->setStyleSheet("QLabel{""color:green;""}");
        ui->Label_netstat->setText("<已连接服务器>");
        ui->Label_netstat2->setStyleSheet("QLabel{""color:green;""}");
        ui->Label_netstat2->setText("<已连接服务器>");
        return;
    }
    else
    {
        connect_server();
        ui->Label_netstat->setStyleSheet("QLabel{""color:red;""}");
        ui->Label_netstat->setText("<请连接服务器>");
        ui->Label_netstat2->setStyleSheet("QLabel{""color:red;""}");
        ui->Label_netstat2->setText("<请连接服务器>");
        return ;
    }
}

void qq_main_menu::closeEvent(QCloseEvent *event)
{
    qDebug()<<"触发界面关闭事假啦"<<endl;
    delete client;
}

void qq_main_menu::on_Button_exit_clicked()
{
    close();
}

void qq_main_menu::on_Button_register_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(1);
    ui->Label_feedback->setText("");
    ui->LE_login2->setText("");
    ui->LE_passwd2->setText("");
}

void qq_main_menu::on_Button_back_login_clicked()
{
    ui->Label_login_stat->setText("");
    ui->main_stacked_widget->setCurrentIndex(0);
}

void qq_main_menu::on_Button_ewm2_clicked()
{
    ui->Label_login_stat->setText("");
    ui->main_stacked_widget->setCurrentIndex(0);
}

void qq_main_menu::on_Button_ewm_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(2);
}

void qq_main_menu::on_Button_go_clicked()
{
    if(!client->connecting())return ;
    if(ui->LE_login->text().size()<7||ui->LE_passwd->text().size()<6)
    {
        ui->Label_login_stat->setText("账号或密码不正确");
        return;
    }
    QString str="login "+ui->LE_login->text()+" "+ui->LE_passwd->text();
    qDebug()<<str<<endl;
    client->send_msg(str);
    Sleep(300);
    ret=client->get_msg().toInt();
    switch(ret)
    {
        case 1:
        {
          qq_list *q_list=new qq_list(client,ui->LE_login->text(),ui->LE_passwd->text());
          q_list->show();
          this->hide();
          connect(q_list,&qq_list::over,this,[=](){delete q_list;this->close();});
        }break;
        case 0:
        {
            ui->Label_login_stat->setText("账号或密码不正确");
            ui->LE_passwd->setText("");
        }break;
        case 2:
        {
            ui->Label_login_stat->setText("账号已登录");
            ui->LE_passwd->setText("");
        }break;
        default:
        {
            ui->Label_login_stat->setText("未知错误——请重试");
        }
    }

}

void qq_main_menu::on_Button_register_go_clicked()
{
    if(!client->connecting())return;
    if(ui->LE_login2->text().size()<7)
    {
        ui->Label_feedback->setText("账号长度不低于7位");
        return;
    }
    else if(ui->LE_passwd2->text().size()<6)
    {
        ui->Label_feedback->setText("密码长度不低于6位");
        return ;
    }
    QString str="register "+ui->LE_login2->text()+" "+ui->LE_passwd2->text();
    qDebug()<<str<<endl;
    client->send_msg(str);
//    waitstat=true;
//    ui->main_stacked_widget->setCurrentIndex(3);
//    while(client->queue_empty())
//    {

//        if(!client->connecting())
//        {
//            ui->Label_feedback->setStyleSheet("QLabel{""color:red;""}");
//            ui->Label_feedback->setText("服务器断开连接——请重试");
//            return ;
//        }
//        if(!waitstat)
//        {
//            return ;
//        }
//    }
    Sleep(300);
    ret=client->get_msg().toInt();
    switch(ret)
    {
        case 1:
        {
            ui->Label_feedback->setStyleSheet("QLabel{""color:green;""}");
            ui->Label_feedback->setText("账户注册成功");
            ui->LE_login2->setText("");
            ui->LE_passwd2->setText("");
        }break;
        case 0:
        {
            ui->Label_feedback->setStyleSheet("QLabel{""color:red;""}");
            ui->Label_feedback->setText("账号已注册");
            ui->LE_login2->setText("");
            ui->LE_passwd2->setText("");
        }break;
        default:
        {
            ui->Label_feedback->setStyleSheet("QLabel{""color:red;""}");
            ui->Label_feedback->setText("未知错误——请重试");
        }
    }

}

void qq_main_menu::on_Button_cancel_clicked()
{

}

void qq_main_menu::on_Button_CG_ip_clicked()
{
    if(client->connect_thread_running)
        client->connect_thread_running=false;
    if(client->connecting())
        client->disconnect();
    delete client;
    client=new internet();
    client->set_addr(ui->LE_IP->text());
    client->set_port(ui->LE_PT->text());
    ui->main_stacked_widget->setCurrentIndex(0);

}

void qq_main_menu::on_Button_CG_back_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(0);
}

void qq_main_menu::on_Button_CG_mr_clicked()
{

    ui->LE_IP->setText("118.31.247.104");
    ui->LE_PT->setText("4397");

}

void qq_main_menu::on_Button_set_clicked()
{
    ui->main_stacked_widget->setCurrentIndex(3);
}
