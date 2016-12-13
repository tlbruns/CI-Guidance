#include "infowidget.h"
const static double err_thresh = 1.0;

InfoWidget::InfoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.button_centerCItool->setObjectName("centerCItool");
	ui.button_centerProbe->setObjectName("centerProbe");

	connect(ui.button_centerCItool, SIGNAL(clicked()), this, SLOT(slot_CenterView()));
	connect(ui.button_centerProbe,  SIGNAL(clicked()), this, SLOT(slot_CenterView()));

}

InfoWidget::~InfoWidget()
{

}

void InfoWidget::slot_NewProbePosition(double x, double y, double z)
{
	ui.label_probe_x->setText( QString::number(x, 'f', 1).rightJustified( 8, ' ', false ) );
	ui.label_probe_y->setText( QString::number(y, 'f', 1).rightJustified( 8, ' ', false ) );
	ui.label_probe_z->setText( QString::number(z, 'f', 1).rightJustified( 8, ' ', false ) );
}

void InfoWidget::slot_NewCIPosition(double x, double y, double z)
{
	ui.label_ci_x->setText( QString::number(x, 'f', 1).rightJustified( 8, ' ', false ) );
	ui.label_ci_y->setText( QString::number(y, 'f', 1).rightJustified( 8, ' ', false ) );
	ui.label_ci_z->setText( QString::number(z, 'f', 1).rightJustified( 8, ' ', false ) );
}

void InfoWidget::slot_NewMagPosition(double x, double y, double z)
{
	ui.label_mag_x->setText( QString::number(x, 'f', 1).rightJustified( 8, ' ', false ) );
	ui.label_mag_y->setText( QString::number(y, 'f', 1).rightJustified( 8, ' ', false ) );
	ui.label_mag_z->setText( QString::number(z, 'f', 1).rightJustified( 8, ' ', false ) );
}

void InfoWidget::slot_update_err(double err_ci, double err_mag)
{
	// Update Error Bars
	int ci_err_bar_value = 0;
	int mag_err_bar_value = 0;

	if (err_ci >100)
		ci_err_bar_value = 0;
	else if (err_ci > 5)
		ci_err_bar_value = -0.7895*err_ci+79;
	else
		ci_err_bar_value = -5.55*err_ci+102.78;

	ui.progressBar_CI_err->setValue(ci_err_bar_value);
	ui.progressBar_mag_err->setValue(mag_err_bar_value);

	// Update Error Values
	ui.label_ci_err->setText( QString::number(err_ci, 'f', 2).rightJustified( 8, ' ', false ) );
	ui.label_mag_err->setText( QString::number(err_mag, 'f', 2).rightJustified( 8, ' ', false ) );

	// Error Check
	if(err_ci<err_thresh)
	{
		QPixmap greencheck (":/images/Resources/greencheck_small.png");
		ui.label_ci_status->setPixmap(greencheck);
	}
	else
	{
		QPixmap redX (":/images/Resources/redX_small.png");
		ui.label_ci_status->setPixmap(redX);
	}

	if(err_mag<1)
	{
		QPixmap greencheck (":/images/Resources/greencheck_small.png");
		ui.label_mag_status->setPixmap(greencheck);
	}
	else
	{
		QPixmap redX (":/images/Resources/redX_small.png");
		ui.label_mag_status->setPixmap(redX);
	}
}

void InfoWidget::slot_CenterView()
{
	QObject *senderObj = sender(); // returns sender object
	QString senderObjName = senderObj->objectName(); // sender name

	emit sgn_CenterView(senderObjName);
}