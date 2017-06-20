#include "infowidget.h"
#include <qcolor.h>

const static double err_thresh_pos = 0.5;
const static double err_thresh_ang = 2;

InfoWidget::InfoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    liveTracking = false;

	// create name used to identify object that triggered slot
	ui.button_centerCItool->setObjectName("centerCItool"); 
	ui.button_centerProbe->setObjectName("centerProbe");

	// hide magnet sections
	ui.MagnetBox->setHidden(true);
	ui.label_text_Magnet->setHidden(true);
	ui.label_text_error2->setHidden(true);
	ui.label_mag_err->setHidden(true);
	ui.progressBar_mag_err->setHidden(true);

    ui.label_FRE->setHidden(true);

	// connect signals/slots
	connect(ui.button_centerCItool, SIGNAL(clicked()), this, SLOT(slot_CenterView()));
	connect(ui.button_centerProbe,  SIGNAL(clicked()), this, SLOT(slot_CenterView()));
    connect(ui.checkBox_LiveTarget, SIGNAL(stateChanged(int)), this, SLOT(slot_Checkbox_LiveTracking(int)));
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

	ui.progressBar_CI_err_pos->setValue(ci_err_bar_value);
	ui.progressBar_mag_err->setValue(mag_err_bar_value);

	// Update Error Values
	ui.label_ci_err_pos->setText( QString::number(err_ci, 'f', 2).rightJustified( 8, ' ', false ) );
	ui.label_mag_err->setText( QString::number(err_mag, 'f', 2).rightJustified( 8, ' ', false ) );

	// Error Check
	if(err_ci<err_thresh_pos)
	{
		QPixmap greencheck (":/images/Resources/greencheck_small.png");
		ui.label_ci_status->setPixmap(greencheck);
	}
	else
	{
		QPixmap redX (":/images/Resources/redX_small.png");
		ui.label_ci_status->setPixmap(redX);
	}

	//if(err_mag<1)
	//{
	//	QPixmap greencheck (":/images/Resources/greencheck_small.png");
	//	ui.label_mag_status->setPixmap(greencheck);
	//}
	//else
	//{
	//	QPixmap redX (":/images/Resources/redX_small.png");
	//	ui.label_mag_status->setPixmap(redX);
	//}
}

void InfoWidget::slot_update_err_theta(double theta)
{
	double theta_d = theta * 180.0 / 3.1415926; // convert to degrees
	double err_bar_start = 10; // minimum error before the bar starts showing anything

	// Update Error Bars
	int err_bar_value = 0;
	if (theta_d > err_bar_start)
		err_bar_value = 0;
	else
		err_bar_value = 100 - pow(10, theta_d / (err_bar_start / err_thresh_ang));

	ui.progressBar_CI_err_ang->setValue(err_bar_value);

	// Update Error Values
	ui.label_ci_err_ang->setText( QString::number(theta_d, 'f', 2).rightJustified( 8, ' ', false ) );

	// Error Check
	if(theta_d<err_thresh_ang)
	{
		QPixmap greencheck (":/images/Resources/greencheck_small.png");
		ui.label_ci_status_ang->setPixmap(greencheck);
	}
	else
	{
		QPixmap redX (":/images/Resources/redX_small.png");
		ui.label_ci_status_ang->setPixmap(redX);
	}
}

void InfoWidget::slot_CenterView()
{
	QObject *senderObj = sender(); // returns sender object
	QString senderObjName = senderObj->objectName(); // sender name

	emit sgn_CenterView(senderObjName);
}

void InfoWidget::slot_Checkbox_LiveTracking(int state)
{
    if (state) {
        ui.label_FRE->setHidden(false);
    }
    else {
        ui.label_FRE->setHidden(true);
    }

    emit sgn_LiveTracking(state);
}

void InfoWidget::slot_NewFre(double fre)
{
    // wait until registration has been performed before allowing user to enable live tracking
    if (fre == 0) {
        liveTracking = true;
        ui.checkBox_LiveTarget->setCheckable(true);
    }
   
    // set color based on fre
    QString freTxt;
    if (fre < 1.0) {
        freTxt.sprintf("FRE = %.2f", fre);
        ui.label_FRE->setText(freTxt);
    }
    else {
        freTxt.sprintf("Warning! FRE = %.2f", fre);
        ui.label_FRE->setText(freTxt);
    }
    
}
