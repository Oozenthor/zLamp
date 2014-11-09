#include "lamps.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Lamps w;
  w.show();

  return a.exec();
}
