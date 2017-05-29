#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include "ui_Info.h"

class InfoWidget : public QWidget
{
	Q_OBJECT

public:
	InfoWidget(QWidget *parent);
	~InfoWidget();

public slots:
	void slot_NewProbePosition(double,double,double);
	void slot_NewCIPosition(double,double,double);
	void slot_NewMagPosition(double,double,double);
	void slot_update_err(double,double);
	void slot_update_err_theta(double);
	void slot_CenterView();

signals:
	void sgn_CenterView(QString);

private:
	Ui::Info	ui;
};

#endif // INFOWIDGET_H
