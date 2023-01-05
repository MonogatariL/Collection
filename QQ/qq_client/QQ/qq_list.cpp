#include "qq_list.h"
#include "ui_qq_list.h"
int ret=0;
QQueue<QString> Split_string(QString msg);
QQueue<QString> Split_string_msg(QString msg);
qq_list::qq_list(internet* client_,QString account_,QString passwd_,QWidget *parent) :client(client_),account(account_),passwd(passwd_),QWidget(parent),ui(new Ui::qq_list)
{
    ui->setupUi(this);

    timerId=startTimer(500);
    timerID2=startTimer(5000);
    timerID3=startTimer(500);
/*基础设置*/
    ui->Label_feedback->setStyleSheet("QLabel{""color:red;""}");
    ui->Label_feedback2->setStyleSheet("QLabel{""color:red;""}");
    ui->Label_account->setText(account);
/*获取名字*/
    client->send_msg(QString("name %1").arg(account));
    for(int i=0;i<5&&client->queue_empty();i++)Sleep(300);
    ui->Label_name->setText(client->get_msg());
/*好友列表tableview设定*/
    tableModel=new QStandardItemModel(this);
    QStringList columnTitles;
    ui->tableView->setModel(tableModel);
    columnTitles<<" "<<" "<<" ";
    tableModel->setHorizontalHeaderLabels(columnTitles);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,210);
    ui->tableView->setColumnWidth(2,20);
    ui->tableView->verticalHeader()->hide();
/*好友请求tableview设定*/
    tableModel2=new QStandardItemModel(this);
    QStringList columnTitles2;
    ui->tableView2->setModel(tableModel2);
    columnTitles2<<" "<<" "<<" ";
    tableModel2->setHorizontalHeaderLabels(columnTitles2);
    ui->tableView2->setColumnWidth(0,215);
    ui->tableView2->setColumnWidth(1,40);
    ui->tableView2->setColumnWidth(2,40);
    ui->tableView2->verticalHeader()->hide();

    ui->LE_add_account->setPlaceholderText("输入账号");
    ui->LE_add_account->clear();
/*设置文本框的输入规则*/
    QRegExp regx_pw("[a-zA-Z0-9_.+-*/]+$");
    QValidator *validator_pw = new QRegExpValidator(regx_pw, ui->LE_CG1 );
    ui->LE_CG1->setValidator( validator_pw );
    ui->LE_CG2->setValidator( validator_pw );
    ui->LE_CG3->setValidator( validator_pw );
    ui->LE_CG1->setEchoMode(QLineEdit::Password);//文本显示模式为密码圆圈
    ui->LE_CG2->setEchoMode(QLineEdit::Password);
    ui->LE_CG3->setEchoMode(QLineEdit::Password);

    on_Button_refresh_clicked();
    //HANDLE thread=(HANDLE)_beginthreadex(NULL,0,chat_msg_thread,(void*)client,0,NULL);
}

qq_list::~qq_list()
{
    qDebug()<<"QQ界面析构啦"<<endl;
    delete ui;
}

void qq_list::on_Button_refresh_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->Label_online->setText("好友：?");
    ui->Label_online->setText("在线：?");
    client->clear();
    if(!client->connecting())return;
    QString str="friends "+ui->Label_account->text();
    client->send_msg(str);
    for(int i=0;i<5&&client->queue_empty();i++){if(!client->connecting())return ;Sleep(300);}
    tableModel->removeRows(0,tableModel->rowCount());
    int people=client->get_msg().toInt();
    ui->Label_friendss->setText("好友："+QString::number(people, 10));
    int online=0;
    if(people==0)
    {
        ui->Label_online->setText("在线："+QString::number(online, 10));
        return;
    }
    for(int i=0;i<5&&client->queue_empty();i++){if(!client->connecting())return ;Sleep(300);}
    QQueue<QString>msg(Split_string(client->get_msg()));

    for(int i = 0; i < people; i++)
    {
        tableModel->setItem(i,0,new QStandardItem(""));

        QPushButton *picture = new QPushButton("");
        QString nm=msg.head();msg.pop_front();//好友昵称
        QString acc=msg.head();msg.pop_front();//好友账户
        QString zai=msg.head();msg.pop_front();//好友在线状况
        QString str="("+nm+")"+acc;

        name_list[acc]=nm;

        QPushButton *name=new QPushButton(str);name->setFixedWidth(220);
        name->setFont(QFont("黑体",10));
        name->setProperty("account",acc);
        QPushButton *gun=new QPushButton("");

        ui->tableView->setIndexWidget(tableModel->index(i,0),picture);
        ui->tableView->setIndexWidget(tableModel->index(i,1),name);
        ui->tableView->setIndexWidget(tableModel->index(i,2),gun);

        if(zai=="1")
        {
            online++;
            picture->setStyleSheet("QPushButton{""border-image:url(:/new/prefix1/res/qq.png);""}");
        }
        else
            picture->setStyleSheet("QPushButton{""border-image:url(:/new/prefix1/res/qq2.png);""}");
        gun->setStyleSheet("QPushButton{""border-image:url(:/new/prefix1/res/gray.png);""}");
        connect(gun,&QPushButton::clicked,this,[=](){
                QString s=QString("确认删除好友吗？");
                int ret=QMessageBox::question(this,"删除好友",s,QMessageBox::Ok,QMessageBox::No);
                switch(ret)
                {
                    case QMessageBox::Ok:
                    {
                        client->send_msg(QString("delete %1 %2").arg(account).arg(name->property("account").toString()));
                    }break;
                }
        });
        connect(name,&QPushButton::clicked,this,[=](){
            if(zai!="1")return;
            if(hash.find(acc)!=hash.end())return;
            chat *c1=new chat(client,acc,nm,ui->Label_name->text());
            hash[acc]=c1;
            connect(c1,&chat::over,this,[=](){
               auto iter=hash.find(acc);
               hash.erase(iter);
               delete c1;
            });
            c1->show();
        });

    }
    ui->Label_online->setText("在线："+QString::number(online, 10));
}
void qq_list::on_Button_check_please_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->LE_add_account->setPlaceholderText("输入账号");
    ui->LE_add_account->clear();
    tableModel2->removeRows(0,tableModel2->rowCount());
    client->clear();
    if(!client->connecting())
        return;
    QString str="check_add "+ui->Label_account->text();
    client->send_msg(str);
    for(int i=0;i<5&&client->queue_empty();i++){if(!client->connecting())return ;Sleep(300);}
    tableModel2->removeRows(0,tableModel2->rowCount());
    int pls=client->get_msg().toInt();
    if(pls==0)
    {
        ui->Label_add_feedback->setText("暂无好友请求");
        return;
    }
    ui->Label_add_feedback->setText("好友请求");
    for(int i=0;i<5&&client->queue_empty();i++){if(!client->connecting())return ;Sleep(300);}
    QQueue<QString>msg(Split_string(client->get_msg()));
    for(int i = 0; i < pls; i++)
    {
        tableModel2->setItem(i,0,new QStandardItem(""));

        QString acc=msg.head();msg.pop_front();
        QPushButton *account=new QPushButton(acc);account->setFont(QFont("黑体",12));
        QPushButton *agreen=new QPushButton("");
        QPushButton *refuse=new QPushButton("");

        ui->tableView2->setIndexWidget(tableModel2->index(i,0),account);account->setFixedWidth(215);
        ui->tableView2->setIndexWidget(tableModel2->index(i,1),agreen);
        ui->tableView2->setIndexWidget(tableModel2->index(i,2),refuse);
        agreen->setStyleSheet("QPushButton{""border-image:url(:/new/prefix1/res/green.png);""}");
        refuse->setStyleSheet("QPushButton{""border-image:url(:/new/prefix1/res/red.png);""}");
        connect(agreen,&QPushButton::clicked,this,[=](){
                QString s=QString("确认添加好友吗？");
                int ret=QMessageBox::question(this,"账号:"+acc,s,QMessageBox::Ok,QMessageBox::No);
                if(ret==QMessageBox::Ok)
                {
                    client->send_msg("agreen "+acc+" "+ui->Label_account->text());
                    Sleep(1000);
                    on_Button_check_please_clicked();
                }
        });
        connect(refuse,&QPushButton::clicked,this,[=](){
                QString s=QString("确认拒绝好友请求吗？");
                int ret=QMessageBox::question(this,"账号:"+acc,s,QMessageBox::Ok,QMessageBox::No);
                if(ret==QMessageBox::Ok)
                {
                    client->send_msg("refuse "+acc+" "+ui->Label_account->text());
                    Sleep(1000);
                    on_Button_check_please_clicked();
                }
        });
//        connect(agreen,&QPushButton::pressed,this,[=](){client->send_msg("agreen "+acc+" "+ui->Label_account->text());});
//        connect(refuse,&QPushButton::pressed,this,[=](){client->send_msg("refuse "+acc+" "+ui->Label_account->text());});
    }
}

void qq_list::closeEvent(QCloseEvent *event)
{
    qDebug()<<"触发关闭事件啦"<<endl;
    for(auto x:hash)
    {
        delete  x.second;
    }
    delete tableModel;
    delete tableModel2;
    emit over();
}

void qq_list::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==timerID3)
    {
        if(client->chat_queue_size())
        {
            QQueue<QString>q(Split_string_msg(client->get_chat_msg()));
            q.pop_front();
            QString from=q.head();q.pop_front();//来自某个账户
            QString msg=q.head();q.pop_front();
            if(hash.find(from)==hash.end())
            {
                QString friend_name;
                //为什么要这样做？因为存在，一个人刚接受玩好友请求，然后好友列表还未刷新录入所有好友的账户昵称键值，这时候只能这样处理一下
                if(name_list.find(from)==name_list.end())
                    friend_name="新朋友";
                else
                    friend_name=name_list[from];
                chat *c1=new chat(client,from,friend_name,ui->Label_name->text());
                hash[from]=c1;
                connect(c1,&chat::over,this,[=](){
                   auto iter=hash.find(from);
                   hash.erase(iter);
                   delete c1;
                });
                c1->show();
                hash[from]->msg.push_front(msg);//丢进去的已经是纯净的消息部分，可以直接取用无须处理
            }
            else
            {
               hash[from]->msg.push_front(msg);
            }
        }
        return ;
    }
    else if(event->timerId()==timerID2)
    {
        if(ui->stackedWidget->currentIndex()==0)
            on_Button_refresh_clicked();
        return;
    }
    else if(client->connect_thread_running)
    {
          ui->Label_netstat->setStyleSheet("QLabel{""color:red;""}");
          ui->Label_netstat->setText("<正在连接服务器...>");
          return;
    }
    else if(client->connecting())
    {
        ui->Label_netstat->setStyleSheet("QLabel{""color:green;""}");
        ui->Label_netstat->setText("<已连接服务器>");

        return;
    }
    else
    {
        ui->Label_netstat->setStyleSheet("QLabel{""color:red;""}");
        ui->Label_netstat->setText("<请连接服务器>");
        return ;
    }
}

void qq_list::on_Button_add_clicked()
{
    if(!client->connecting())return;
    if(ui->LE_add_account->text().size()<7)
    {
        ui->LE_add_account->setPlaceholderText("请设置有效账号");
        ui->LE_add_account->clear();
        return;
    }
    if(ui->LE_add_account->text()==account)
    {
        ui->LE_add_account->setPlaceholderText("和自己做朋友？也不错");
        ui->LE_add_account->clear();
        return;
    }
    QString msg="add_pls "+account+" "+ui->LE_add_account->text();
    client->send_msg(msg);Sleep(100);
    for(int i=0;i<5&&client->queue_empty();i++)Sleep(300);
    ret=client->get_msg().toInt();
    switch(ret)
    {
        case 1:
        {
           ui->LE_add_account->setPlaceholderText("已发送请求");
        }break;
        case 0:
        {
            ui->LE_add_account->setPlaceholderText("未知账户");
        }break;
        default:
        {
            ui->LE_add_account->setPlaceholderText("未知错误——请重试");
        }
    }
    ui->LE_add_account->clear();
}

void qq_list::on_Button_quit_clicked()
{
    this->close();
}

void qq_list::on_Button_set_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->Label_feedback->setText("");
    ui->LE_CG1->setText("");
    ui->LE_CG2->setText("");
    ui->LE_CG3->setText("");
    ui->Label_feedback->setStyleSheet("QLabel{""color:red;""}");

}

void qq_list::on_Button_CG_clicked()
{
    ui->Label_feedback->setStyleSheet("QLabel{""color:red;""}");
    if(!client->connect())
    {
        ui->Label_feedback->setText("网络连接错误");
        return ;
    }
    if(ui->LE_CG1->text()!=passwd)
    {
        ui->Label_feedback->setText("初始密码错误");
        return ;
    }
    if(ui->LE_CG2->text().size()<6)
    {
        ui->Label_feedback->setText("密码长度不得低于6位");
        return ;
    }
    if(ui->LE_CG2->text()!=ui->LE_CG3->text())
    {
        ui->Label_feedback->setText("两次密码不一致");
        return ;
    }
    client->send_msg("change "+account+" "+ui->LE_CG2->text());
    Sleep(300);
    ret=client->get_msg().toInt();
    switch(ret)
    {
        case 1:
        {
           ui->Label_feedback->setStyleSheet("QLabel{""color:green;""}");
           ui->LE_CG1->setText("");
           ui->LE_CG2->setText("");
           ui->LE_CG3->setText("");
           ui->Label_feedback->setText("修改成功");
           passwd=ui->LE_CG2->text();
        }break;
        case 0:
        {
             ui->Label_feedback->setText("修改失败,请重试");
        }break;
        default:
        {
             ui->Label_feedback->setText("未知错误——请重试");
        }
    }

}

void qq_list::on_Button_CG_NM_clicked()
{
    ui->Label_feedback2->setStyleSheet("QLabel{""color:red;""}");
    if(!client->connect())
    {
        ui->Label_feedback2->setText("网络连接错误");
        return ;
    }
    if(ui->LE_CG_NM->text().size()<1)
    {
        ui->Label_feedback2->setText("昵称不能为空");
        return ;
    }
    for(auto x:ui->LE_CG_NM->text())
    {
        if(x==' ')
        {
            ui->Label_feedback2->setText("昵称不能带空格");
            return ;
        }
    }
    client->send_msg("rename "+account+" "+ui->LE_CG_NM->text());
    Sleep(300);
    ret=client->get_msg().toInt();
    switch(ret)
    {
        case 1:
        {
           ui->Label_feedback2->setStyleSheet("QLabel{""color:green;""}");
           ui->Label_feedback2->setText("修改成功");
           ui->Label_name->setText(ui->LE_CG_NM->text());
        }break;
        case 0:
        {
             ui->Label_feedback2->setText("修改失败,请重试");
        }break;
        default:
        {
             ui->Label_feedback2->setText("未知错误——请重试");
        }
    }
}

QQueue<QString> Split_string(QString msg)
{
    QString str=msg;
    QString s;
    QQueue<QString>res;
    for(auto x:str)
    {
        if(x==' ')
        {
            res.enqueue(s);
            s="";
        }
        else
        {
            s+=x;
        }
    }
    if(s.size())
        res.enqueue(s);
    return res;
}
QQueue<QString> Split_string_msg(QString msg)
{
    QString str=msg;
    QString s;
    QQueue<QString>res;
    for(auto x:str)
    {
        if(x==' '&&res.size()<2)
        {
            res.enqueue(s);
            s="";
        }
        else
        {
            s+=x;
        }
    }
    if(s.size())
        res.enqueue(s);
    return res;
}
