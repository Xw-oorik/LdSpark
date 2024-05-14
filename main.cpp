#include "mainwindow.h"
#include <QApplication>
#include <QLoggingCategory>
int main(int argc, char *argv[]) {
  QApplication::setHighDpiScaleFactorRoundingPolicy(
      Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
  QApplication a(argc, argv);
  QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
  MainWindow w;
  w.show();

  return a.exec();
}
