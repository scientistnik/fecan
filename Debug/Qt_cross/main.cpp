#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //QTimer *timer = new QTimer(w);
    //connect(timer, SIGNAL(timeout()), w, SLOT(updateCaption()));
    //timer->start(1000);

    return a.exec();
}
