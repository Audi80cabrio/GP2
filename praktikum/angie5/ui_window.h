#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QMainWindow>
#include "ui_widget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr) {
        setCentralWidget(new MainWidget(this));
        setWindowTitle("Ufo");
        setFixedSize(250, 230);
    }

    ~MainWindow() = default;
};

#endif // UI_WINDOW_H
