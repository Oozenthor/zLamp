#include "zlamp.h"

ZLamp::ZLamp()
{

}

ZLamp::ZLamp(QRect rect, QColor color, bool lit)
{
  lampColor = color;
  lampLit = lit;
  bezelRect = rect;// Bezel bounding rectangle

  Dimension();
}

ZLamp::~ZLamp()
{

}

void ZLamp::Dimension()
{
  // Bezel width
  bezelWidth = 7;

  // Lamp bounding rectangle
  lampRect=bezelRect.adjusted(bezelWidth, bezelWidth, -bezelWidth, -bezelWidth);

  // Bezel shading
  bezelGradient = QLinearGradient(bezelRect.topRight(), bezelRect.bottomLeft());
  bezelGradient.setColorAt(0.0, QColor(Qt::darkGray));
  bezelGradient.setColorAt(1.0, QColor(Qt::black));

  lampRadius = bezelWidth * lampRect.width()/bezelRect.width();

  // Lamp "Bright spot"
//  focalPoint = lampRect.center() + QPoint(lampRect.width()/4, -lampRect.height()/4);
  focalPoint = lampRect.center();
}

void ZLamp::Render(QPainter &painter)
{
  // Set Lamp color intensities
  if (!lampLit) {
    lampColor.setHsv(lampColor.hue(), lampColor.saturation(), lampColor.value()*0.2);
  }
  lampColorLow.setHsv(lampColor.hue(), lampColor.saturation(), lampColor.value()*0.8);

  // Set Lamp gradients
//  lampGradient = QRadialGradient(focalPoint, lampRect.height());
  lampGradient = QRadialGradient(focalPoint, 2);
  lampGradient.setColorAt(0.0, lampColor);
/*  lampGradient.setColorAt(0.1, lampColorLow);
  lampGradient.setColorAt(0.2, lampColor);
  lampGradient.setColorAt(0.3, lampColorLow);
  lampGradient.setColorAt(0.4, lampColor);
*/  lampGradient.setColorAt(1.0, lampColorLow);
  lampGradient.setSpread(QGradient::ReflectSpread);

  // Draw everything
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Qt::NoPen);

  painter.setBrush(bezelGradient);
  painter.drawRoundedRect(bezelRect, bezelWidth, bezelWidth);

  painter.setBrush(lampGradient);
  painter.drawRoundedRect(lampRect, lampRadius, lampRadius);
}

