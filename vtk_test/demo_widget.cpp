#include "demo_widget.h"
#include "ui_Demo.h"
#include <qdialog.h>

Demo_Widget::Demo_Widget(QWidget *parent)
	: QDialog(parent),
	ui(new Ui::Demo)
{
	ui->setupUi(this);
	connect(ui->button_set_target, SIGNAL(clicked()), this, SLOT(slot_button_set_target()));
	connect(ui->button_datalog, SIGNAL(clicked()), this, SLOT(slot_button_datalog()));
}

Demo_Widget::~Demo_Widget()
{
	delete ui;
}

void Demo_Widget::slot_button_set_target()
{
	emit sgn_SetTarget();
}

void Demo_Widget::slot_button_datalog()
{
	// disable Set Target button and enable Save Data button
	connect(ui->button_end, SIGNAL(clicked()), this, SLOT(slot_button_end()));
	disconnect(ui->button_set_target, SIGNAL(clicked()), this, SLOT(slot_button_set_target()));

	ui->button_datalog->setText(QString("Collecting..."));
	ui->button_end->setText(QString("Done"));
	emit sgn_DatalogStart();
}

void Demo_Widget::slot_button_end()
{
	// re-enable Set Target button
	connect(ui->button_set_target, SIGNAL(clicked()), this, SLOT(slot_button_set_target()));

	ui->button_end->setText(QString("Data Saved"));
	ui->button_datalog->setText(QString("Record Data"));
	emit sgn_DatalogStop();
}