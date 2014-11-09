#include "zlamp.h"

ZLamp::ZLamp()
{

}

ZLamp::ZLamp(QPoint point, QColor color, bool lit, int diameter)
{
  center = point;
  lampColor = color;
  lampLit = lit;
  bezelDiameter = diameter;

  Dimension();
}

ZLamp::~ZLamp()
{

}

void ZLamp::Dimension()
{
  // Bezel width
  bezelWidth = bezelDiameter / 6;

  // Bezel bounding rectangle
  QPoint bezelTopLeft = QPoint(center.x() - (bezelDiameter / 2), center.y() - (bezelDiameter / 2));
  QSize bezelSize = QSize(bezelDiameter, bezelDiameter);
  bezelRect = QRect(bezelTopLeft, bezelSize);

  // Bezel outline path
  bezelPath.moveTo(center);
  bezelPath.arcTo(bezelRect, 0, 360);

  // Bezel shading
  bezelGradient = QLinearGradient(bezelRect.topRight(), bezelRect.bottomLeft());
  bezelGradient.setColorAt(0.0, QColor(Qt::darkGray));
  bezelGradient.setColorAt(1.0, QColor(Qt::black));

  // Lamp bounding rectangle
  int lampDiameter = bezelDiameter - (bezelWidth * 2);
  QPoint lampTopLeft = QPoint(center.x() - (lampDiameter / 2), center.y() - (lampDiameter / 2));
  QSize lampSize = QSize(lampDiameter, lampDiameter);
  lampRect = QRect(lampTopLeft, lampSize);

  // Lamp outline path
  lampPath.moveTo(center);
  lampPath.arcTo(lampRect, 0, 360);

  // Lamp "Bright spot"
  focalPoint = QPoint(center.x() + (bezelDiameter / 8), center.y() - (bezelDiameter / 8));
}

void ZLamp::Render(QPainter &painter)
{
  // Set Lamp color intensities
  if (!ledLit) {
    lampColor.setHsv(lampColor.hue(), lampColor.saturation(), lampColor.value()*0.2);
  }
  lampColorLow.setHsv(lampColor.hue(), lampColor.saturation(), lampColor.value()*0.4);

  // Set Lamp gradients
  lampGradient = QRadialGradient(focalPoint, lampRect.width());
  lampGradient.setColorAt(0.0, lampColor);
  lampGradient.setColorAt(1.0, lampColorLow);

  // Draw everything
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Qt::NoPen);

  painter.setBrush(bezelGradient);
  painter.drawPath(bezelPath);

  painter.setBrush(lampGradient);
  painter.drawPath(lampPath);
}

