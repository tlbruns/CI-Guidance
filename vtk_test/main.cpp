#include "vtk_test.h"
#include <QtWidgets/QApplication>
#include <QVTKWidget.h>
#include <qmetatype.h>
#include <Eigen/Dense>

Q_DECLARE_METATYPE(Eigen::MatrixXd);

int main(int argc, char *argv[])
{
	printf("Hi");
	Eigen::MatrixXd A;
	qRegisterMetaType<Eigen::MatrixXd>(&A);

	QApplication a(argc, argv);
	vtk_test w;
	w.Initialize();
	w.show();

	return a.exec();
}
