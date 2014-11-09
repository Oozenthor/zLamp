#ifndef LAMPS_H
#define LAMPS_H

#include <QDialog>

namespace Ui {
class Lamps;
}

class Lamps : public QDialog
{
  Q_OBJECT

public:
  explicit Lamps(QWidget *parent = 0);
  ~Lamps();

private:
  Ui::Lamps *ui;
};

#endif // LAMPS_H
