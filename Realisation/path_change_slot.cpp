#include "../Headers/widget.h"
#include "../Headers/path_change_dialog.h"

void widget::path_change_slot()
{
	path_change* dlg = new path_change;

	if (dlg->exec() == QDialog::Accepted)
	{
		if (path_file->isOpen())
			path_file->close();

		path_file->open(QIODevice::WriteOnly);

		path_stream << dlg->get_path();

		path_file->close();
	}

	delete dlg;
}
