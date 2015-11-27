#ifndef FIXTURES_H
#define FIXTURES_H

#include <QDialog>

namespace Ui {
class Fixtures;
}

class Fixtures : public QDialog
{
    Q_OBJECT

public:
    explicit Fixtures(QWidget *parent = 0);
    ~Fixtures();

private:
    Ui::Fixtures *ui;
};

#endif // FIXTURES_H
