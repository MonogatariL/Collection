#pragma once

#include "ui_page_preview.h"
#include "Global.h"
#include "Syurui_Manager.h"
#include "Book_Manager.h"
#include "Login.h"
#include "charts/Charts.h"
#include "Quantity_Manager.h"
class page_preview : public QWidget
{
	Q_OBJECT

public:
	page_preview(QWidget *parent = Q_NULLPTR);
	~page_preview();
	void init();

	void init_TableW_book();
	void update_TableW_book();
	void update_TableW_book2();
	void update_ComboBox_syurui();
	void update_Data();
private:
	Syurui_Manager* sy_manager;
	Book_Manager* bk_manager;
	Login* user_manager;
	Quantity_Manager* qt_manager;
	Charts* chart_manager;



	QStringList strListHead;
	QStringList strListHead2;
	Ui::page_previewClass ui;
	QVector<QStandardItem*>destruct_ptr;/*ºß,ÏëÌÓ£¿*/
	QVector<QPushButton*>destruct_ptr2;/*ºß,ÏëÌÓ£¿*/
	QVector<QPushButton*>destruct_ptr3;/*ºß,ÏëÌÓ£¿*/
protected:
	void keyPressEvent(QKeyEvent* key);
public slots:
	void getRowColumn(int, int);

};
