#include "../Headers/path_change_dialog.h"

path_change::path_change(QWidget* parent) :
	QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
	// COMMON SETTINGS //
	setFixedSize(350, 140);
	setWindowTitle("New path");
	///

	// FILES SETTINGS //
	path_stream.setDevice(path_file);
	path_stream.setCodec("Widnows-1251");

	rpath_stream.setDevice(rpath_file);
	path_stream.setCodec("Widnows-1251");

	path_file->setFileName("path.ini");
	rpath_file->setFileName("rpath.ini");
	///

	// LABLES //
	tip_lbl->setText(TO_RUS("���������: ������ ���� ������ ���� �������."
	"\n���� ���� �� ��������, ������ ������� �������� ����������"
	"\n��� �� ������� �������� �����."
	"\n���� ������������� ��������� � ����������� \"txt\"."
	"\n������: C:\\Users\\Admin\\Desktop\\save.txt"));
	///

	// LINE EDIT //
	input_lne->setMaxLength(100);

	if (rpath_file->isOpen())
		rpath_file->close();

	rpath_file->open(QIODevice::ReadOnly);

	input_lne->setText(rpath_stream.readAll());
	input_lne->selectAll();

	rpath_file->close();
	///

	// BUTTONS //
	apply_btn->setText("OK");

	cancel_btn->setText(TO_RUS("��������"));

	connect(cancel_btn, SIGNAL(clicked()), SLOT(reject()));
	connect(apply_btn, SIGNAL(clicked()), SLOT(accept()));
	///

	// LAYOUTS //
	lay_1->addWidget(tip_lbl);

	lay_2->addWidget(input_lne);

	lay_3->addWidget(apply_btn);
	lay_3->addWidget(cancel_btn);

	main_lay->addLayout(lay_1);
	main_lay->addLayout(lay_2);
	main_lay->addLayout(lay_3);

	setLayout(main_lay);
	///
}

QString path_change::get_path()
{
	QString old_str = input_lne->text();
	QString new_str;

	for (int i = 0; i <= old_str.size(); i++)
	{
		if (old_str[i] != '\\')
		{
			new_str.push_back(old_str[i]);
		}
		else
		{
			new_str.push_back("\\\\");
		}
	}

	return new_str;
}
