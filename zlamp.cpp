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
  bezelWidth = bezelRect.height()/12;

  // Lamp bounding rectangle
  lampRect=bezelRect.adjusted(bezelWidth, bezelWidth, -bezelWidth, -bezelWidth);

  // Bezel shading
  bezelGradient = QLinearGradient(bezelRect.topRight(), bezelRect.bottomLeft());
  bezelGradient.setColorAt(0.0, QColor(Qt::darkGray));
  bezelGradient.setColorAt(1.0, QColor(Qt::black));

  lampRadius = bezelWidth * lampRect.width()/bezelRect.width();

  // Lamp "Bright spot"
  lampGradient = QRadialGradient(lampRect.center(), 2);
  lampGradient.setSpread(QGradient::ReflectSpread);

  lampFont = QFont("Arial", lampRect.height()*0.6, QFont::DemiBold);
}

void ZLamp::setText(QString text)
{
  lampText = text;
}

void ZLamp::Render(QPainter &painter)
{
  // Set Lamp color intensities
  if (!lampLit) {
    lampColor.setHsv(lampColor.hue(), lampColor.saturation(), lampColor.value()*0.2);
  }
  lampColorLow.setHsv(lampColor.hue(), lampColor.saturation(), lampColor.value()*0.8);

  // Set Lamp gradients
  lampGradient.setColorAt(0.0, lampColor);
  lampGradient.setColorAt(1.0, lampColorLow);

  // Draw everything
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Qt::NoPen);
  painter.setBrush(bezelGradient);
  painter.drawRoundedRect(bezelRect, bezelWidth, bezelWidth);

  painter.setPen(Qt::NoPen);
  painter.setBrush(lampGradient);
  painter.drawRoundedRect(lampRect, lampRadius, lampRadius);

  painter.setPen(Qt::black);
  painter.setFont(lampFont);
  painter.drawText(lampRect, Qt::AlignCenter ,lampText);

}


