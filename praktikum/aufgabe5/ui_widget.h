
#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QFrame>
#include <QMessageBox>
#include "ufo.h"
#include "ufo_thread.h"
#include "vertical.h"

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget* parent = nullptr) : QWidget(parent) {
        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        QFormLayout* formLayout = new QFormLayout();

        xEdit = new QLineEdit();
        yEdit = new QLineEdit();
        heightEdit = new QLineEdit();
        speedEdit = new QLineEdit();

        formLayout->addRow("x:", xEdit);
        formLayout->addRow("y:", yEdit);
        formLayout->addRow("height:", heightEdit);
        formLayout->addRow("speed:", speedEdit);
        mainLayout->addLayout(formLayout);

        startButton = new QPushButton("Start");
        mainLayout->addWidget(startButton);

        plabel = new QLabel("\n\n\n", this);
        plabel->setFrameShape(QFrame::Box);
        plabel->setFrameShadow(QFrame::Plain);
        mainLayout->addWidget(plabel);

        ufo = new Vertical("U1");
        uthread = new UfoThread(ufo);

        connect(startButton, &QPushButton::clicked, this, &MainWidget::startUfo);
        connect(uthread, &UfoThread::stopped, this, &MainWidget::updateWindow);
    }

    ~MainWidget() {
        if (uthread) uthread->stopAndJoin();  // hier ist das join welches Sie vermisst haben :)
        delete uthread;
        delete ufo;
    }


private slots:
    void startUfo() {
        bool okX, okY, okH, okS;
        float x = xEdit->text().toFloat(&okX);
        float y = yEdit->text().toFloat(&okY);
        float h = heightEdit->text().toFloat(&okH);
        int s = speedEdit->text().toInt(&okS);

        if (!okX) { xEdit->setText("error: must be float"); clearLabel();}
        if (!okY) { yEdit->setText("error: must be float"); clearLabel();}
        if (!okH) { heightEdit->setText("error: must be float"); clearLabel();}
        if (!okS) { speedEdit->setText("error: must be int"); clearLabel();}

        if (!okX) {return; }
        if (!okY) {return; }
        if (!okH) {return; }
        if (!okS) {return; }

        uthread->startUfo(x, y, h, s);

        std::vector<float> pos = ufo->getPosition();
        QString text = QString("    Started at\n    Position:\n    X: %1 | Y: %2 | H: %3")
                            .arg(pos[0], 0, 'f', 2)
                            .arg(pos[1], 0, 'f', 2)
                            .arg(pos[2], 0, 'f', 2);
        plabel->setText(text);

        startButton->setText("Flying");
        startButton->setEnabled(false);
    }

    void updateWindow(std::vector<float> pos) {
        QString text = QString("    Flight completed at\n    Position:\n    X: %1 | Y: %2 | H: %3")
                            .arg(pos[0], 0, 'f', 2)
                            .arg(pos[1], 0, 'f', 2)
                            .arg(pos[2], 0, 'f', 2);
        plabel->setText(text);

        startButton->setText("Start");
        startButton->setEnabled(true);
    }

private:
    void clearLabel() {
        plabel->setText("\n\n\n");
    }

    QLineEdit* xEdit;
    QLineEdit* yEdit;
    QLineEdit* heightEdit;
    QLineEdit* speedEdit;
    QPushButton* startButton;
    QLabel* plabel;

    Ufo* ufo;
    UfoThread* uthread;
};

#endif // UI_WIDGET_H
