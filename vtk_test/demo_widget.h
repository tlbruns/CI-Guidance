#ifndef DEMO_WIDGET_H
#define DEMO_WIDGET_H

#include <QDialog>
#include <ui_Demo.h>
#include <qtimer.h>

namespace Ui {
	class Demo_Widget;}

class Demo_Widget : public QDialog
{
	Q_OBJECT

public:
	explicit Demo_Widget(QWidget *parent=0);
	~Demo_Widget();

private:


public slots:
	void slot_button_set_target();
	void slot_button_datalog();
	void slot_button_end();

signals:
	void sgn_SetTarget();
	void sgn_DatalogStart();
	void sgn_DatalogStop();

private:
	Ui::Demo	*ui;

};

#endif // DEMO_WIDGET_H