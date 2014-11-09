#ifndef ZLAMP_H
#define ZLAMP_H
// Display some nice panel lamps with a bezel using QPainter

#include <QPainter>
#include <QPainterPath>

class ZLamp
{
public:
  ZLamp();
  ZLamp(QRect rect, QColor color=Qt::red, bool lit=true);
  ~ZLamp();

  void Render(QPainter &painter);
  void setText(QString text);

private:
  void Dimension(void);
  QPoint center;

  QRect bezelRect;
  QPainterPath bezelPath;
  QLinearGradient bezelGradient;

  int bezelWidth;
//  qreal bezelRadius;

  QRect lampRect;
  QPainterPath lampPath;
  QRadialGradient lampGradient;

  QColor lampColor;
  QColor lampColorLow;
  bool lampLit;
  qreal lampRadius;

  QFont lampFont;
  QString lampText;
};

#endif // ZLAMP_H
