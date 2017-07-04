#include "CI_Guidance.h"
#include <QtWidgets/QApplication>
#include <QVTKWidget.h>
#include <qmetatype.h>
#include <Eigen/Dense>

Q_DECLARE_METATYPE(Eigen::MatrixXd);

int main(int argc, char *argv[])
{
	Eigen::MatrixXd A;
	qRegisterMetaType<Eigen::MatrixXd>(&A);

	QApplication a(argc, argv);
	CI_Guidance w;
	w.Initialize();
	w.show();

	return a.exec();
}
