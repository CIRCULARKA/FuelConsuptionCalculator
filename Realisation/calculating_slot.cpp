#include "../Headers/widget.h"
#include "../Headers/add_percentage.h"

void widget::calculating_slot()
{
	//���������� true, ���� ��� ������ ������� ���������
	arrival_spbx->setMaximum(departure_spbx->value());
	if (departure_spbx->value() == 0)
		arrival_spbx->setDisabled(true);
	else arrival_spbx->setDisabled(false);

	if ((arrival_spbx->value() < departure_spbx->value()) &&
		(trucks_cmbx->currentIndex() != 0 && months_cmbx->currentIndex() != 0))
	{
		data_is_validate = true;
	}
	else
	{
		data_is_validate = false;
		result_ldt->setText(TO_RUS("0 �."));
	}
	write_btn->setEnabled(data_is_validate);
	///

	//������ �������
	if (data_is_validate)
	{
		departure_indications = arrival_spbx->text().toFloat();
		return_indications = departure_spbx->text().toFloat();
		mileage = return_indications - departure_indications;

		switch (trucks_cmbx->currentIndex())
		{
		case 1:
			consuption_per_100_km = 29.0;
			add_percentage(mileage, 10.0);
			break;
		case 2:
			consuption_per_100_km = 30.0;
			break;
		case 3:
			consuption_per_100_km = 35.0;
			add_percentage(mileage, 10.0);
			break;
		case 4:
			consuption_per_100_km = 37.0;
			break;
		case 5:
			consuption_per_100_km = 25.5;
			add_percentage(mileage, 10.0);
			break;
		}

		if (months_cmbx->currentIndex() >= 5 && months_cmbx->currentIndex() <= 11)
			mileage = mileage;
		else if (months_cmbx->currentIndex() >= 1 && months_cmbx->currentIndex() <= 3)
			add_percentage(mileage, 18.0);
		else if (months_cmbx->currentIndex() == 4 || months_cmbx->currentIndex() == 12)
		{
			double mileage_first_part = mileage / 2.0, mileage_second_part = mileage / 2.0;
			add_percentage(mileage_first_part, 18.0);
			mileage = mileage_first_part + mileage_second_part;
		}
		///

		total_consuption = (mileage / 100.0) * consuption_per_100_km;

		result_ldt->setText(QString::number(total_consuption) + TO_RUS(" �."));
	}
}
