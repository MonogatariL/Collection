#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    int square;//用于保存窗口除以格子后的平均值，便于使用。
    bool black=true;//black为true，意味着轮到黑棋，反之白棋。
    int theme_skin=1;//保存当前的主题号，胜利时相应的提示
    QPixmap white_chess;//保存白棋的主题
    QPixmap black_chess;//保存黑棋的主题
    QPixmap background;//保存背景主题
    QLabel *l;//状态栏下的文本，时刻更新下一个出棋方
    QVector<QVector<QPair<QRect,int>>>press_board;//核心，存储了棋盘的点击范围、当前位置是否已有子等信息。
private:
    Ui::MainWindow *ui;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void Win(int x,int y);//判断胜利条件
    void Statu_show();//状态栏更新
    void change_theme(int key);//主题更换
    void initialization();//初始化，用于重新游戏
};
#endif // MAINWINDOW_H
