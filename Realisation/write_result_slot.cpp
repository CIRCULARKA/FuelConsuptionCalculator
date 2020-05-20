#include "../Headers/widget.h"

void widget::write_result_slot()
{
	if (path_file->isOpen())
		path_file->close();

	path_file->open(QIODevice::ReadOnly);

	saves_file->setFileName(path_file->readAll());

	path_file->close();

	if (saves_file->isOpen())
		saves_file->close();

	//���������� � ������������ ����� ���������� ��� �������� �����
	if (saves_file->exists())
	{
		saves_file->open(QIODevice::WriteOnly | QIODevice::Append);

		saves_stream << months_cmbx->currentText() <<
			trucks_cmbx->currentText() << result_ldt->text() << "\n";
	}
	else
	{
		saves_file->open(QIODevice::WriteOnly);

		saves_stream << TO_RUS("�����     ")
			<< TO_RUS("������    ")
			<< TO_RUS("������    ") << "\n\n";

		saves_stream << months_cmbx->currentText() <<
			trucks_cmbx->currentText() << result_ldt->text() << "\n";
	}

	saves_file->close();
}
