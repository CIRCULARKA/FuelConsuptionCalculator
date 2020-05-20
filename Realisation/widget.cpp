#include "../Headers/widget.h"
#include "../Headers/path_change_dialog.h"

widget::widget(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);

	// COMMON SETTINGS //
	setWindowTitle("Fuel Consuption");
	setFixedSize(250, 215);

	QApplication::setStyle(QStyleFactory::create("Breeze"));
	///

	// ACTIONS //
	connect(exit_menu_action, &QAction::triggered, this, &QWidget::close);
	connect(path_change_menu_action, &QAction::triggered, this, &widget::path_change_slot);
	///

	// MENU //
	main_mnu->addAction(path_change_menu_action);
	main_mnu->addSeparator();
	main_mnu->addAction(exit_menu_action);

	menu_bar->setFixedSize(250, 22);
	menu_bar->addMenu(main_mnu);
	///

	// TEXT FIELDS //
	departure_lbl->setText(TO_RUS("��� ������"));
	departure_lbl->setAlignment(Qt::AlignCenter);

	arrival_lbl->setText(TO_RUS("��� �����������"));
	arrival_lbl->setAlignment(Qt::AlignCenter);

	truck_lbl->setText(TO_RUS("������"));
	truck_lbl->setAlignment(Qt::AlignCenter);

	month_lbl->setText(TO_RUS("�����"));
	month_lbl->setAlignment(Qt::AlignCenter);

	result_lbl->setText(TO_RUS("")); // �������
	result_lbl->setAlignment(Qt::AlignCenter);
	///

	// SPIN BOXES //
	arrival_spbx->setMaximum(999999);
	arrival_spbx->setDisabled(true);
	connect(arrival_spbx, SIGNAL(valueChanged(int)), this, SLOT(calculating_slot()));

	departure_spbx->setMaximum(999999);
	connect(departure_spbx, SIGNAL(valueChanged(int)), this, SLOT(calculating_slot()));
	///

	// COMBO BOXES //
	trucks_cmbx->addItem("-");
	trucks_cmbx->addItem("FREDLINER ");
	trucks_cmbx->addItem(TO_RUS("��� 1     "));
	trucks_cmbx->addItem(TO_RUS("��� 2     "));
	trucks_cmbx->addItem(TO_RUS("����      "));
	trucks_cmbx->addItem(TO_RUS("�����     "));
	connect(trucks_cmbx, &QComboBox::currentTextChanged, this, &widget::calculating_slot);

	months_cmbx->addItem("-");
	months_cmbx->addItem(TO_RUS("������    "));
	months_cmbx->addItem(TO_RUS("�������   "));
	months_cmbx->addItem(TO_RUS("����      "));
	months_cmbx->addItem(TO_RUS("������    "));
	months_cmbx->addItem(TO_RUS("���       "));
	months_cmbx->addItem(TO_RUS("����      "));
	months_cmbx->addItem(TO_RUS("����      "));
	months_cmbx->addItem(TO_RUS("������    "));
	months_cmbx->addItem(TO_RUS("��������  "));
	months_cmbx->addItem(TO_RUS("�������   "));
	months_cmbx->addItem(TO_RUS("������    "));
	months_cmbx->addItem(TO_RUS("�������   "));
	connect(months_cmbx, &QComboBox::currentTextChanged, this, &widget::calculating_slot);
	///

	// LINE EDIT //
	result_ldt->setText(TO_RUS("0 �."));
	result_ldt->setAlignment(Qt::AlignCenter);
	result_ldt->setReadOnly(true);
	///

	// BUTTONS SETTINGS //
	write_btn->setText(TO_RUS("��������"));
	write_btn->setEnabled(false);
	connect(write_btn, SIGNAL(clicked()), this, SLOT(write_result_slot()));
	///

	// FILES SETTINGS //
	saves_stream.setDevice(saves_file);
	saves_stream.setCodec("Widnows-1251");

	path_stream.setCodec("Windows-1251");
	path_stream.setDevice(path_file);

	path_file->setFileName("path.ini");
	///

	// GROUP BOXES //
	meter_gpbx->setTitle(TO_RUS("��������� ����������"));
	meter_gpbx->setAlignment(Qt::AlignCenter);
	meter_gpbx->setFixedSize(250, 68);
	meter_gpbx->setGeometry(0, 23, 0, 0);

	result_gpbx->setTitle(TO_RUS("���������"));
	result_gpbx->setAlignment(Qt::AlignCenter);
	result_gpbx->setFixedSize(250, 73);
	result_gpbx->setGeometry(0, 136, 0, 0);
	///

	// LAYOUTS //
	hlay_1_main->addWidget(arrival_lbl);
	hlay_1_main->addWidget(departure_lbl);

	hlay_2_main->addWidget(departure_spbx);
	hlay_2_main->addWidget(arrival_spbx);

	hlay_3_main->addWidget(truck_lbl);
	hlay_3_main->addWidget(month_lbl);

	hlay_4_main->addWidget(trucks_cmbx);
	hlay_4_main->addWidget(months_cmbx);

	hlay_5_main->addWidget(result_lbl);

	hlay_6_main->addWidget(result_ldt);

	hlay_7_main->addWidget(write_btn);

	main_vlay->addSpacerItem(spacer_item);
	main_vlay->addLayout(hlay_1_main);
	main_vlay->addLayout(hlay_2_main);
	main_vlay->addLayout(hlay_3_main);
	main_vlay->addLayout(hlay_4_main);
	main_vlay->addLayout(hlay_5_main);
	main_vlay->addLayout(hlay_6_main);
	main_vlay->addLayout(hlay_7_main);

	setLayout(main_vlay);
	///
}
