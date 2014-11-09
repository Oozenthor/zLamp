#ifndef LAMPS_H
#define LAMPS_H

#include <QDialog>
#include <QPainter>
#include <QTimer>

#include "zlamp.h"

namespace Ui {
class Lamps;
}

class Lamps : public QDialog
{
  Q_OBJECT

public:
  explicit Lamps(QWidget *parent = 0);
  ~Lamps();

protected:
  void paintEvent(QPaintEvent *event);

private slots:
  void on_toggleButton_clicked();
  void cycleLamps();

private:
  Ui::Lamps *ui;
  bool toggle;
  QTimer *timer;

};

#endif // LAMPS_H
