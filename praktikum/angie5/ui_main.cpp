// ui_main.cpp
#include "ui_window.h"
#include "ui_widget.h"

#include <QApplication>
#include "ui_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
