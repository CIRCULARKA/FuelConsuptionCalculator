#pragma once

#include "widget.h"

class path_change : public QDialog
{
	Q_OBJECT

public:
	path_change(QWidget* parent = 0);

	QString get_path();

private:
	QLineEdit* input_lne = new QLineEdit;

	QLabel* tip_lbl = new QLabel;

	QPushButton* apply_btn = new QPushButton;
	QPushButton* cancel_btn = new QPushButton;

	QFile* path_file = new QFile;
	QFile* rpath_file = new QFile;

	QTextStream path_stream;
	QTextStream rpath_stream;

	QVBoxLayout* main_lay = new QVBoxLayout;

	QHBoxLayout* lay_1 = new QHBoxLayout;
	QHBoxLayout* lay_2 = new QHBoxLayout;
	QHBoxLayout* lay_3 = new QHBoxLayout;
};