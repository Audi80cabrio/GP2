
#pragma once

#include <QObject>
#include <thread>
#include <atomic>
#include <vector>
#include "ufo.h"

class UfoThread : public QObject {
    Q_OBJECT

private:
    std::thread* flyThread = nullptr;
    Ufo* ufo;
    std::atomic<bool> isFlying = false;

    void runner(const float x, const float y, const float height, const int speed) {
        isFlying = true;
        ufo->flyToDest(x, y, height, speed);
        isFlying = false;
        emit stopped(ufo->getPosition());
    }

public:
    UfoThread(Ufo* pUfo) : ufo(pUfo) {}

    ~UfoThread() {
        if (flyThread != nullptr) {
            if (flyThread->joinable()) {
                flyThread->join();
            }
            delete flyThread;
        }
    }

    void startUfo(const float x, const float y, const float height, const int speed) {
        if (flyThread != nullptr) {
            if (flyThread->joinable()) {
                flyThread->join();
            }
            delete flyThread;
        }

        flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
    }

    bool getIsFlying() const {
        return isFlying.load();
    }

signals:
    void stopped(std::vector<float>);
};
