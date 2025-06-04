#include "ufo_thread.h"
#include <thread>

UfoThread::UfoThread(Ufo* pUfo) : ufo(pUfo) {}

UfoThread::~UfoThread() {
    if (flyThread) {
        if (flyThread->joinable()) {
            flyThread->join();
        }
        delete flyThread;
        flyThread = nullptr;
    }
}

void UfoThread::startUfo(const float x, const float y, const float height, const int speed) {
    if (flyThread != nullptr) {
        if (flyThread->joinable()) {
            flyThread->join();
        }
        delete flyThread;
        flyThread = nullptr;
    }

    isFlying = true;
    flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);

    // kurze pause, damit der Thread starten kann, bevor der unit-test abkackt
    std::this_thread::yield();
}

bool UfoThread::getIsFlying() const {
    return isFlying;
}

void UfoThread::runner(const float x, const float y, const float height, const int speed) {
    ufo->flyToDest(x, y, height, speed);
    isFlying = false;
}
