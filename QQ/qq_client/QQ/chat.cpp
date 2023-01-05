#include "chat.h"
#include "ui_chat.h"

chat::chat(internet* client_,QString acc_,QString friend_n_,QString my_n_,QWidget *parent) :
    client(client_),acc(acc_),friend_n(friend_n_),my_n(my_n_),QWidget(parent),ui(new Ui::chat)
{
    ui->setupUi(this);
    timerID=startTimer(500);
    this->setWindowTitle(acc);
    this->setWindowIcon(QPixmap(":/new/prefix1/res/face2.png"));
    ui->TE_smsg->installEventFilter(this);
}

chat::~chat()
{
    delete ui;
}

void chat::push_msg(QString msg_)
{
    msg.push_back(msg_);
}


void chat::on_Button_close_clicked()
{
    close();
}

void chat::on_Button_send_clicked()
{
    if(ui->TE_smsg->toPlainText().size())
    {
        client->send_msg("to "+acc+" "+ui->TE_smsg->toPlainText());
        QDateTime dateTime = QDateTime::currentDateTime();
        QString timestamp = my_n+" "+dateTime.toString("yyyy-MM-dd hh:mm:ss");
        timestamp=QStringLiteral("<font color= green>%1</font>").arg(timestamp);
        ui->TE_msg->append(timestamp);
        ui->TE_msg->append(" "+ui->TE_smsg->toPlainText());
        ui->TE_smsg->clear();
        //移动光标到末尾
        QTextCursor cursor = ui->TE_msg->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->TE_msg->setTextCursor(cursor);
    }
}

void chat::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key()<<endl;
    if(event->key()==16777220)
        on_Button_send_clicked();
}

void chat::closeEvent(QCloseEvent *event)
{
    emit over();
}

void chat::timerEvent(QTimerEvent *event)
{
    while(msg.size())
    {
        QDateTime dateTime = QDateTime::currentDateTime();
        QString timestamp =friend_n+" "+dateTime.toString("yyyy-MM-dd hh:mm:ss");
        timestamp=QStringLiteral("<font color= blue>%1</font>").arg(timestamp);
        ui->TE_msg->append(timestamp);
        ui->TE_msg->append(" "+msg.front());
        msg.pop_front();

        QTextCursor cursor = ui->TE_msg->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->TE_msg->setTextCursor(cursor);
    }
}

bool chat::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->TE_smsg)
    {
        if(event->type() == QEvent::KeyPress)//回车键
        {
             QKeyEvent *k = static_cast<QKeyEvent *>(event);
             if(k->key() == Qt::Key_Return)
             {
                 on_Button_send_clicked();
                 return true;
             }
        }
    }
    return QWidget::eventFilter(target,event);
}
