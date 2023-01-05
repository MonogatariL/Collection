#ifndef QQ_LIST_H
#define QQ_LIST_H

#include <QWidget>
#include <QtWidgets>
#include <QVector>
#include <QQueue>
#include "chat.h"
#include"internet.h"
namespace Ui {
class qq_list;
}

class qq_list : public QWidget
{
    Q_OBJECT

public:
    explicit qq_list(internet* client_,QString account_,QString passwd_,QWidget *parent = nullptr);
    //qq_list(QWidget *parent=nullptr);
    ~qq_list();
public:
    QStandardItemModel *tableModel,*tableModel2;
    internet *client;
    QString account;
    QString passwd;
    int timerId,timerID2,timerID3;
    map<QString,chat*>hash;
    map<QString,QString>name_list;
private slots:
    void on_Button_refresh_clicked();

    void on_Button_add_clicked();

    void on_Button_check_please_clicked();

    void on_Button_quit_clicked();

    void on_Button_set_clicked();

    void on_Button_CG_clicked();

    void on_Button_CG_NM_clicked();


protected:
      void closeEvent(QCloseEvent *event);
      void timerEvent(QTimerEvent* event);
signals:
      void over();
private:
    Ui::qq_list *ui;
};

#endif // QQ_LIST_H
