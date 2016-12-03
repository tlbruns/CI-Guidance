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
	connect(ui->button_end, SIGNAL(clicked()), this, SLOT(slot_button_end()));
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
	emit sgn_DatalogStart();
}

void Demo_Widget::slot_button_end()
{
	emit sgn_DatalogStop();
}