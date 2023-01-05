#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QtWidgets>
#include"internet.h"
namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(internet *client_,QString acc_,QString friends_n_,QString my_n_,QWidget *parent = nullptr);
    ~chat();

    void push_msg(QString);
    internet *client;
    QString acc;
    QString my_n;
    QString friend_n;
    QQueue<QString>msg;
    int timerID;
signals:
      void over();
private slots:
    void on_Button_close_clicked();

    void on_Button_send_clicked();
protected:
      void keyPressEvent(QKeyEvent* event);
      void closeEvent(QCloseEvent *event);
      void timerEvent(QTimerEvent* event);
      bool eventFilter(QObject *target, QEvent *event);
private:
    Ui::chat *ui;
};

#endif // CHAT_H
