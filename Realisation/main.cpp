#include "../Headers/widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	widget w;

	w.show();

	return a.exec();
}
