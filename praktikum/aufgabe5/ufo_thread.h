#pragma once

#include <QObject>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include "ufo.h"
#include "vertical.h"

class UfoThread : public QObject {
    Q_OBJECT

private:
    std::thread* flyThread = nullptr;   // jetzt auch auf dem Heap erhältlich
    Vertical* vert = nullptr;
    std::atomic<bool> isFlying = false;
    std::mutex threadMutex;

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
        stopAndJoin();
    }


    void startUfo(const float x, const float y, const float height, const int speed) {
        std::lock_guard<std::mutex> lock(threadMutex);

        if (isFlying) return;

        if (flyThread && flyThread->joinable()) flyThread->join();
        delete flyThread;
        flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
    }

    void stopAndJoin() {
        if (flyThread && flyThread->joinable()) flyThread->join();
        delete flyThread;
        flyThread = nullptr;
    }

    bool getIsFlying() const {
        return isFlying;
    }

signals:
    void stopped(std::vector<float>);
};
