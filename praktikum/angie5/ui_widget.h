
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>
#include <QString>
#include <QMessageBox>

#include "ufo.h"
#include "ufo_thread.h"
#include "vertical.h"

#define GRID_SIZE 3

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QMainWindow *parent = nullptr) : QWidget(parent)
    {
        grid = new QGridLayout();
        grid->setSpacing(5);

        editX = new QLineEdit("", this);
        editY = new QLineEdit("", this);
        editH = new QLineEdit("", this);
        editS = new QLineEdit("", this);

        grid->addWidget(new QLabel("X:"), GRID_SIZE, 0);
        grid->addWidget(editX, GRID_SIZE, 1);
        grid->addWidget(new QLabel("Y:"), GRID_SIZE+1, 0);
        grid->addWidget(editY, GRID_SIZE+1, 1);
        grid->addWidget(new QLabel("H:"), GRID_SIZE+2, 0);
        grid->addWidget(editH, GRID_SIZE+2, 1);
        grid->addWidget(new QLabel("S:"), GRID_SIZE+3, 0);
        grid->addWidget(editS, GRID_SIZE+3, 1);

        plabel = new QLabel("\n\n\n", this);
        plabel->setFrameShape(QFrame::Box);
        plabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        plabel->setMinimumHeight(50);
        grid->addWidget(plabel, GRID_SIZE, 2, 4, 1);

        startButton = new QPushButton("Start", this);
        grid->addWidget(startButton, GRID_SIZE+4, 0, 1, 3);
        connect(startButton, SIGNAL(clicked()), this, SLOT(startUfo()));

        ufo = new Vertical("UFO-1");
        uthread = new UfoThread(ufo);

        connect(uthread, SIGNAL(stopped(std::vector<float>)), this, SLOT(updateWindow(std::vector<float>)));

        setLayout(grid);
    }

    ~MainWidget()
    {
        delete uthread;
        delete ufo;
        delete grid;

        for (int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                delete buttons[i][j];

        delete plabel;
        delete startButton;
        delete editX;
        delete editY;
        delete editH;
        delete editS;
    }

private slots:
    void changeText()
    {
        plabel->setText("Ein Button wurde geklickt");
    }

    void startUfo()
    {
        bool okX, okY, okH, okS;
        float x = editX->text().toFloat(&okX);
        float y = editY->text().toFloat(&okY);
        float h = editH->text().toFloat(&okH);
        int s = editS->text().toInt(&okS);

        if (!okX) { editX->setText("error: must be float"); plabel->setText("");}
        if (!okY) { editY->setText("error: must be float"); plabel->setText("");}
        if (!okH) { editH->setText("error: must be float"); plabel->setText("");}
        if (!okS) { editS->setText("error: must be int"); plabel->setText("");}

        if (!okX) { return;}
        if (!okY) { return;}
        if (!okH) { return;}
        if (!okS) { return;}

        uthread->startUfo(x, y, h, s);

        std::vector<float> pos = ufo->getPosition();
        QString infoText = QString("Started at\nPosition:\nX: %1 | Y: %2 | H: %3")
                               .arg(QString::number(pos[0], 'f', 2))
                               .arg(QString::number(pos[1], 'f', 2))
                               .arg(QString::number(pos[2], 'f', 2));
        plabel->setText(infoText);

        startButton->setText("Flying");
        startButton->setEnabled(false);
    }

    void updateWindow(std::vector<float> pos)
    {
        QString infoText = QString("Flight completed at\nPosition:\nX: %1 | Y: %2 | H: %3")
                               .arg(QString::number(pos[0], 'f', 2))
                               .arg(QString::number(pos[1], 'f', 2))
                               .arg(QString::number(pos[2], 'f', 2));
        plabel->setText(infoText);

        startButton->setText("Start");
        startButton->setEnabled(true);
    }

private:
    QGridLayout *grid;
    QPushButton* buttons[GRID_SIZE][GRID_SIZE];
    QLabel* plabel;
    QPushButton* startButton;

    QLineEdit *editX, *editY, *editH, *editS;

    Ufo* ufo;
    UfoThread* uthread;
};

#endif // MAINWIDGET_H
