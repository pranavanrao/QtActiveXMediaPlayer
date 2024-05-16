#include "mainwindow.h"

#include <QApplication>
#include <QAxWidget>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QAxWidget* axWidget = new QAxWidget(&w);

    if (!axWidget->setControl("{6BF52A52-394A-11D3-B153-00C04F79FAA6}")) {
        QMessageBox::critical(nullptr, "Error", "Could not initiate windows media player activeX");
        return -1;
    }

    axWidget->setGeometry(10, 10, 680, 480);

    axWidget->dynamicCall("URL", "C:\\Users\\prana\\OneDrive\\Desktop\\QT-QML-projects\\QtAxMediaPlayer\\random-video.mp4");

    w.show();
    return a.exec();
}
