#include "Pivot_Calibration.h"
#include "ui_Pivot_Calibration.h"
#include <qdialog.h>



Pivot_Calibration::Pivot_Calibration(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::PivotCalibration)
{
    ui->setupUi(this);

}

void Pivot_Calibration::slot_onNewToolTransform(Eigen::Matrix4d)
{

}

Pivot_Calibration::~Pivot_Calibration()
{
}
