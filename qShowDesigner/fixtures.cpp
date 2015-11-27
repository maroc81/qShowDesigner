#include "fixtures.h"
#include "ui_fixtures.h"

Fixtures::Fixtures(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fixtures)
{
    ui->setupUi(this);
}

Fixtures::~Fixtures()
{
    delete ui;
}
