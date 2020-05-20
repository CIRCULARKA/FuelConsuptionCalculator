#pragma once

#include <QtWidgets/QWidget>
#include "ui_widget.h"

#include <qlabel.h>
#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qtextstream.h>
#include <qfile.h>
#include <qtextcodec.h>
#include <qmenubar.h>
#include <qaction.h>
#include <qinputdialog.h>
#include <qstring.h>
#include <qmessagebox.h>
#include <qstylefactory.h>

#define TO_RUS QString::fromLocal8Bit

class widget : public QWidget
{
	Q_OBJECT

public:
	widget(QWidget *parent = Q_NULLPTR);

public slots:
	void path_change_slot();
	void calculating_slot();
	void write_result_slot();

private:
	Ui::widgetClass ui;

	QString str = "sdsad sdaaa";

	QAction* exit_menu_action = new QAction(TO_RUS("Выход"));
	QAction* path_change_menu_action = new QAction(TO_RUS("Путь сохранения"));

	QMenuBar* menu_bar = new QMenuBar(this);

	QMenu* main_mnu = new QMenu(TO_RUS("Настройки"), this);
	QMenu* exit_submnu = new QMenu("Exit", menu_bar);

	QSpacerItem* spacer_item = new QSpacerItem(0, 40);

	QLabel* departure_lbl = new QLabel;
	QLabel* arrival_lbl = new QLabel;
	QLabel* truck_lbl = new QLabel;
	QLabel* month_lbl = new QLabel;
	QLabel* result_lbl = new QLabel;
	QLabel* truck_msgbx_lbl = new QLabel;

	QSpinBox* arrival_spbx = new QSpinBox;
	QSpinBox* departure_spbx = new QSpinBox;

	QComboBox* trucks_cmbx = new QComboBox;
	QComboBox* months_cmbx = new QComboBox;

	QPushButton* write_btn = new QPushButton;

	QLineEdit* result_ldt = new QLineEdit;

	QVBoxLayout* main_vlay = new QVBoxLayout;
	QVBoxLayout* add_truck_msgbx_vlay = new QVBoxLayout;

	//Нумерация сверху вниз
	QHBoxLayout* hlay_1_main = new QHBoxLayout;
	QHBoxLayout* hlay_2_main = new QHBoxLayout;
	QHBoxLayout* hlay_3_main = new QHBoxLayout;
	QHBoxLayout* hlay_4_main = new QHBoxLayout;
	QHBoxLayout* hlay_5_main = new QHBoxLayout;
	QHBoxLayout* hlay_6_main = new QHBoxLayout;
	QHBoxLayout* hlay_7_main = new QHBoxLayout;
	QHBoxLayout* add_truck_msgbx_hlay_1 = new QHBoxLayout;
	QHBoxLayout* add_truck_msgbx_hlay_2 = new QHBoxLayout;
	QHBoxLayout* add_truck_msgbx_hlay_3 = new QHBoxLayout;

	QGroupBox* meter_gpbx = new QGroupBox(this);
	QGroupBox* result_gpbx = new QGroupBox(this);

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");

	QFile* saves_file = new QFile;
	QFile* path_file = new QFile;

	QTextStream saves_stream;
	QTextStream path_stream;

	double departure_indications;
	double return_indications;
	double mileage;
	double consuption_per_100_km;
	double total_consuption;

	bool data_is_validate;
	bool ok_btn;
};