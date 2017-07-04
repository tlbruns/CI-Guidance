#pragma once
#include "qdialog.h"
#include "ui_Pivot_Calibration.h"
#include <Eigen/dense>
#include <qvector.h>

namespace Ui {
    class Pivot_Calibration;}

class Pivot_Calibration : public QDialog
{
    Q_OBJECT

public:
    explicit Pivot_Calibration(QWidget *parent = 0);
    ~Pivot_Calibration();

    Eigen::Vector3d tOffset(void); // returns tOffset_; must call computeOffset() first
    Eigen::Vector3d tPivot(void);  // returns tPivot_

public slots:
    void slot_onNewAitTransform(Eigen::Matrix4d); // updates currentT_
    void slot_takeSample(); // saves currentT_ to R_
    void slot_computeOffset();
    void slot_reset();

private:
    bool computeOffset(void); // 

    Eigen::Matrix4d currentT_; // most recent transform received by slot_onNewToolTransform()
    Ui::PivotCalibration *ui;
    QVector<Eigen::Matrix3d> R_;
    QVector<Eigen::Vector3d> t_;
    Eigen::Vector3d tOffset_; // translational offset between tool and pivot point
    Eigen::Vector3d tPivot_;  // location of pivot point
};

