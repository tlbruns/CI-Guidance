#include "Pivot_Calibration.h"
#include "ui_Pivot_Calibration.h"
#include <qdialog.h>



Pivot_Calibration::Pivot_Calibration(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::PivotCalibration)
{
    ui->setupUi(this);

    connect(ui->pushButton_takeSample, SIGNAL(clicked()), this, SLOT(slot_takeSample()));
    connect(ui->pushButton_computeOffset, SIGNAL(clicked()), this, SLOT(slot_computeOffset()));
    connect(ui->pushButton_reset, SIGNAL(clicked()), this, SLOT(slot_reset()));
}

void Pivot_Calibration::slot_onNewAitTransform(Eigen::Matrix4d currentT)
{
    currentT_ = currentT;
}

Pivot_Calibration::~Pivot_Calibration()
{
}

Eigen::Vector3d Pivot_Calibration::tOffset(void)
{
    return tOffset_;
}

Eigen::Vector3d Pivot_Calibration::tPivot(void)
{
    return tPivot_;
}

void Pivot_Calibration::slot_takeSample()
{
    R_.push_back(currentT_.block<3, 3>(0, 0));
    t_.push_back(currentT_.block<3, 1>(0, 3));

    ui->label_numSamples->setText(QString::number(R_.size()));
}

void Pivot_Calibration::slot_computeOffset()
{
    if (computeOffset()) {
        // update labels
    }
    else {

    }
}

void Pivot_Calibration::slot_reset()
{
    R_.clear();
    t_.clear();

    ui->label_numSamples->setText(QString::number(0));
    ui->label_offsetX->setText(QString("-000.00"));
    ui->label_offsetY->setText(QString("-000.00"));
    ui->label_offsetZ->setText(QString("-000.00"));
    ui->label_pivotX->setText(QString("-0000.00"));
    ui->label_pivotY->setText(QString("-0000.00"));
    ui->label_pivotZ->setText(QString("-0000.00"));
}

bool Pivot_Calibration::computeOffset(void)
{
    /*
    Uses the Algebraic Two Step method (Yaniv 2015) to compute 
    the translation offset using the collected data

    Solves the following linear system:
    R_star * t_offset = t_star

    where:
    R_star = [ (R_1 - R_2) ; (R_2 - R_3) ; ... ; (R_n-1 - R_n) ]
    t_star = [ (t_2 - t_1) ; (t_3 - t_2) ; ... ; (t_n - t_n-1) ]
    t_offset = translational offset from tool base frame to pivot point
    */


    // check that R_ and t_ have the same number of samples
    int sizeR = R_.size();
    int sizet = t_.size();

    if (sizeR != sizet) {
        return false;
    }

    // assemble R_star
    Eigen::MatrixX3d R_star(3*(sizeR-1), 3);
    for (int ii = 0; ii < (sizeR-1); ++ii) {
        R_star.block<3, 3>(3 * ii, 0) = R_.at(ii) - R_.at(ii + 1);
    }

    // assemble t_star
    Eigen::VectorXd t_star(3 * (sizeR-1));
    for (int ii = 0; ii < (sizeR - 1); ++ii) {
        t_star.block<3, 1>(3 * ii, 0) = t_.at(ii + 1) - t_.at(ii);
    }

    // solve for t_offset
    tOffset_ = R_star.colPivHouseholderQr().solve(t_star);

    // solve for tPivot => tPivot = mean(Ri * tOffset + ti)
    Eigen::Vector3d tTotal = Eigen::Vector3d::Zero();
    for (int ii = 0; ii < sizeR; ++ii) {
        tTotal = tTotal + (R_.at(ii) * tOffset_ + t_.at(ii));
    }
    tPivot_ = tTotal / (double)sizeR;

    // update labels
    ui->label_offsetX->setText(QString::number(tOffset_(0)));
    ui->label_offsetY->setText(QString::number(tOffset_(1)));
    ui->label_offsetZ->setText(QString::number(tOffset_(2)));
    ui->label_pivotX->setText(QString::number(tPivot_(0)));
    ui->label_pivotY->setText(QString::number(tPivot_(1)));
    ui->label_pivotZ->setText(QString::number(tPivot_(2)));

    return true;
}
