#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QMainWindow>
#include "ui_widget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    MainWidget *mainWidget = new MainWidget(this);

public:
    MainWindow(QWidget* parent = nullptr) {
        setCentralWidget(mainWidget);
        setWindowTitle("Ufo");
        setFixedSize(250, 230);
    }

    ~MainWindow(){delete mainWidget;};
};

#endif // UI_WINDOW_H
