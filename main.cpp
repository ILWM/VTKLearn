#include <QApplication>
#include <memory>
#include "mainwindow.h"
#include "XDataModelHandle.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return QApplication::exec();
}
