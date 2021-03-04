#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtDebug>
#include<QPaintEvent>
#include<QPainter>
#include<QVector>
#include<QStatusBar>
#include<QLabel>
#include"config.h"
#include<QDialog>
#include<QMessageBox>
#include<QAction>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,800);
    setWindowTitle("五子棋");
    change_theme(1);
    square=800/(ChessBoard_size+1);
    QStatusBar *main_status=statusBar();l=new QLabel();main_status->addWidget(l);Statu_show();
    //初始化数组
    for(int i=0;i<ChessBoard_size;i++)
    {
        press_board.push_back(QVector<QPair<QRect,int>>());
        for(int j=0;j<ChessBoard_size;j++)
            press_board[i].push_back(QPair<QRect,int>(QRect((i+1)*square-square/3,(j+1)*square-square/3,square/3*2.5,square/3*2.5),-1));
    }
    //菜单栏的信号槽关联
    connect(ui->New_Game,&QAction::triggered,this,[=](){initialization();});
    connect(ui->skin1,&QAction::triggered,this,[=](){change_theme(1);});
    connect(ui->skin2,&QAction::triggered,this,[=](){change_theme(2);});
    connect(ui->skin3,&QAction::triggered,this,[=](){change_theme(3);});
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;pen.setWidth(3);painter.setPen(pen);//设置棋盘线的宽度
    painter.drawPixmap(0,0,width(),height(),background);//设置背景
    int one_width=width()/(ChessBoard_size+1);
    int one_height=height()/(ChessBoard_size+1);
    int value=ChessBoard_size+1;
    int w=0;
    int h=0;
    for(int i=0;i<ChessBoard_size;i++)//画15条线，这里的画线写法是一个学习点*
    {
        w+=one_width;
        h+=one_height;
        //painter.drawLine(w,0,w,height());
        painter.drawLine(w,one_height,w,height()/value*(value-1));
        //painter.drawLine(0,h,width(),h);
        painter.drawLine(one_width,h,width()/value*(value-1),h);
    }
    pen.setWidth(8);painter.setPen(pen);
    painter.drawPoint(width()/2,height()/2);//中心点标注

    //以上是绘制棋盘，接下来就是绘制棋子
    for(auto x:press_board)
    {
        for(auto y:x)
        {
            //painter.drawRect(y.first);
            switch(y.second)
            {
                case 1:painter.drawPixmap(y.first,black_chess);break;
                case 0:painter.drawPixmap(y.first,white_chess);break;
                case -1:break;
                default:break;
            }
        }
    }


}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x=event->x();
    int y=event->y();
    QRect R(x,y,5,5);//点击的触摸大小
    //核心是判断是否点击在周围的格子，这里是一个难点*
    for(int i=0;i<press_board.size();i++)
    {
        for(int j=0;j<press_board[i].size();j++)
        {
            if(press_board[i][j].first.intersects(R)&&press_board[i][j].second==-1)
            {
                //qDebug()<<(i+1)*50<<" "<<(j+1)*50;
                press_board[i][j].second=black;
                black=!black;
                Win(i,j);
                Statu_show();

            }
        }
    }

    update();
}
void MainWindow::Win(int x,int y)
{
    int position1[4][2]={   {-1,0},//上下
                            {0,-1},//左右
                            {-1,-1},//左上右下
                            {1,-1}};//左下右上
    int position2[4][2]={   {1,0},//上下
                            {0,1},//左右
                            {1,1},//左上右下
                            {-1,1}};//左下右上
    for(int i=0;i<4;i++)
    {
        int sum=0;
        int a,b;
        a=x;b=y;
        for(int j=0;j<4;j++)
        {
            a+=position1[i][0];
            b+=position1[i][1];
            if(a>0&&b>0&&a<press_board.size()&&b<press_board.size()&&press_board[a][b].second==(!black))
                sum++;
        }
        a=x;b=y;
        for(int j=0;j<4;j++)
        {
            a+=position2[i][0];
            b+=position2[i][1];
            if(a>0&&b>0&&a<press_board.size()&&b<press_board.size()&&press_board[a][b].second==(!black))
                sum++;
            else
                break;
        }
        if(sum>=4)
        {
            QString str;
            if(black)
            {
                switch (theme_skin)
                {
                case 1:str=("白棋胜利");break;
                case 2:str=("承太郎胜利");break;
                case 3:str=("利威胜利");break;
                default:str=("白棋胜利");break;
                }
            }
            else
            {
                switch (theme_skin)
                {
                case 1:str=("黑棋胜利");break;
                case 2:str=("迪奥胜利");break;
                case 3:str=("吉克胜利");break;
                default:str=("黑棋胜利");break;
                }
            }
            int ret=QMessageBox::question(this,str,"继续游戏？",QMessageBox::Ok,QMessageBox::No);
            switch(ret)
            {
                case QMessageBox::Ok:initialization();break;
                case QMessageBox::No:close();break;
            }
        }
    }


}
void MainWindow::Statu_show()
{
    if(black)l->setText("轮到黑方");
    else    l->setText("轮到白方");
}
void MainWindow::change_theme(int key)
{
    theme_skin=key;
    switch (key)
    {
case 1: this->setWindowIcon(QPixmap(":/new/prefix1/res/Title1.png"));
        white_chess.load(":/new/prefix1/res/shiro.png");
        black_chess.load(":/new/prefix1/res/kuro.png");
        background.load(":/new/prefix1/res/BackGround1.png");break;
case 2: this->setWindowIcon(QPixmap(":/new/prefix1/res/Title2.png"));
        white_chess.load(":/new/prefix1/res/Kujo_Jotaro.png");
        black_chess.load(":/new/prefix1/res/Dio_Brando.png");
        background.load(":/new/prefix1/res/BackGround_DIO.VS.JOTARO.png");break;
case 3: this->setWindowIcon(QPixmap(":/new/prefix1/res/Title3.png"));
        white_chess.load(":/new/prefix1/res/Levi.png");
        black_chess.load(":/new/prefix1/res/Zeke_Jaeger.png");
        background.load(":/new/prefix1/res/BackGround_Levi.VS.Zeke.png");break;
    }
    update();

}
void MainWindow::initialization()
{
    for(auto &x:press_board)
    {
        for(auto &y:x)
            y.second=-1;
    }
    black=true;
    Statu_show();
    update();
}

