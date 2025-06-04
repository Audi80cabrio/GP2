
#pragma once

#include <QObject>
#include <thread>
#include <atomic>
#include "ufo.h"
#include "vertical.h"

class UfoThread : public QObject {
    Q_OBJECT

private:
    std::thread* flyThread = nullptr;
    Vertical* vert = nullptr;
    std::atomic<bool> isFlying = false;

    void runner(const float x, const float y, const float height, const int speed) {
        isFlying = true;
        vert->flyToDest(x, y, height, speed);
        isFlying = false;
        emit stopped(vert->getPosition());
    }

public:
    UfoThread(Ufo* pUfo) {
        vert = dynamic_cast<Vertical*>(pUfo);
    }

    ~UfoThread() {
        if (flyThread && flyThread->joinable()) {
            flyThread->join();
            delete flyThread;
        }
    }

    void startUfo(const float x, const float y, const float height, const int speed) {
        if (!isFlying) {
            flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
        }
    }

    bool getIsFlying() const {
        return isFlying;
    }

signals:
    void stopped(std::vector<float>);
};
