#pragma once

#include <QDialog>
#include "ui_TrackerSetup.h"

namespace Ui {
	class TrackerSetup;
}

class TrackerSetup : public QDialog
{
	Q_OBJECT

public:
	explicit TrackerSetup(int comPort, QWidget *parent = Q_NULLPTR);
	~TrackerSetup();

public slots:
	void slot_button_select();
	void slot_button_cancel();

signals:
	void sgn_SelectComPort(int value);

private:
	Ui::TrackerSetup *ui;
	int comPort;
};
