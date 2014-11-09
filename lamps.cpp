#include "lamps.h"
#include "ui_lamps.h"

Lamps::Lamps(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Lamps)
{
  ui->setupUi(this);
  toggle = true;

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(cycleLamps()));
  timer->start(500);
}

Lamps::~Lamps()
{
  delete ui;
}

void Lamps::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  QPainter painter(this);

  /*
  ZLamp redLamp(QRect(50, 50, 200, 70), Qt::red, toggle );
  redLamp.Render(painter);
  ZLamp greenLamp(QRect(50, 150, 200, 70), Qt::green, toggle );
  greenLamp.Render(painter);

  ZLamp redLamp(QPoint(50, 50), Qt::red, toggle );
  redLamp.Render(painter);
  ZLamp greenLamp(QPoint(150, 50), Qt::green, toggle );
  greenLamp.Render(painter);
  ZLamp blueLamp(QPoint(250, 50), Qt::blue, toggle );
  blueLamp.Render(painter);

  ZLamp whiteLamp(QPoint(50, 150), Qt::white, toggle );
  whiteLamp.Render(painter);
  ZLamp cyanLamp(QPoint(150, 150), Qt::cyan, toggle );
  cyanLamp.Render(painter);
  ZLamp magentaLamp(QPoint(250, 150), Qt::magenta, toggle );
  magentaLamp.Render(painter);

  ZLamp yellowLamp(QPoint(50, 250), Qt::yellow, toggle );
  yellowLamp.Render(painter);
  ZLamp lightGrayLamp(QPoint(150, 250), Qt::lightGray, toggle );
  lightGrayLamp.Render(painter);
*/
  int x, y, col;

  for(y=0; y<3; y++) {
    for(x=0; x<3; x++) {
      col = 6 + qrand() % 7;
      if (col == 6) {
        col = 3; //white
      }
      QColor color =  (Qt::GlobalColor)(col);
//      QColor color =  QColor((127 + qrand() % 128), (127 + qrand() % 128), (127 + qrand() % 128));
      ZLamp Lamp(QRect(50+x*200, 50+y*80, 180, 70), color, qrand() % 2);
      Lamp.setText(QString::number( color.red(), 16).leftJustified(2,'0')
                   + QString::number( color.green(), 16).leftJustified(2,'0')
                   + QString::number( color.blue(), 16).leftJustified(2,'0'));
      Lamp.Render(painter);
    }
  }
}

void Lamps::on_toggleButton_clicked()
{
  if (toggle) {
    timer->stop();
  } else {
    timer->start();
  }
  toggle = !toggle;
  QWidget::update();
}

void Lamps::cycleLamps()
{
  QWidget::update();
}
