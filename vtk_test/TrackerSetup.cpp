#include "TrackerSetup.h"
#include "ui_TrackerSetup.h"
#include <qdialog.h>

TrackerSetup::TrackerSetup(int comPort,QWidget *parent)
	: QDialog(parent),
	ui(new Ui::TrackerSetup)
{
	ui->setupUi(this);
	this->comPort = comPort;
	for (int i = 0; i < 10; i++) {
		int auxPort;
		auxPort = i + 1;
		ui->comboBox_COM->insertItem(i, tr("%1").arg(auxPort));
	}
	ui->comboBox_COM->setCurrentIndex(this->comPort);
	connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(slot_button_cancel()));
	connect(ui->selectButton, SIGNAL(clicked()), this, SLOT(slot_button_select()));
	connect(this, SIGNAL(sgn_SelectComPort(int)), parent, SLOT(slot_update_COM(int)));
}

TrackerSetup::~TrackerSetup()
{
	delete ui;
}

void TrackerSetup::slot_button_select() {
	int thePort = 0;
	thePort = ui->comboBox_COM->currentIndex();
	emit sgn_SelectComPort(thePort);
	this->close();
}

void TrackerSetup::slot_button_cancel() {
	this->close();
}
