#ifndef ZLAMP_H
#define ZLAMP_H
// Display some nice panel lamps with a bezel using QPainter

#include <QPainter>
#include <QPainterPath>

class ZLamp
{
public:
  ZLamp();
  ZLamp(QPoint point, QColor color=Qt::red, bool lit=true, int diameter=80);
  ~ZLamp();

  void Render(QPainter &painter);

private:
  void Dimension(void);
  QPoint center;

  QRect bezelRect;
  QPainterPath bezelPath;
  QLinearGradient bezelGradient;

  int bezelDiameter;
  int bezelWidth;

  QRect lampRect;
  QPainterPath lampPath;
  QRadialGradient lampGradient;

  QColor lampColor;
  QColor lampColorLow;
  bool lampLit;

  QPoint focalPoint;
};

#endif // ZLAMP_H
