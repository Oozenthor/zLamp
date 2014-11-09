#include "lamps.h"
#include "ui_lamps.h"

Lamps::Lamps(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Lamps)
{
  ui->setupUi(this);
}

Lamps::~Lamps()
{
  delete ui;
}
