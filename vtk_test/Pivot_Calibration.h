#pragma once
#include "qdialog.h"
#include "ui_Pivot_Calibration.h"
#include <Eigen/dense>

namespace Ui {
    class Pivot_Calibration;}

class Pivot_Calibration : public QDialog
{
    Q_OBJECT

public:
    explicit Pivot_Calibration(QWidget *parent = 0);
    ~Pivot_Calibration();


public slots:
    void slot_onNewToolTransform(Eigen::Matrix4d);


private:
    Ui::PivotCalibration *ui;

};

