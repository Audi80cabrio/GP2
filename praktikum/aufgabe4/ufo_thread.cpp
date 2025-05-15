#include "ufo_thread.h"
#include <iostream>

UfoThread::UfoThread(Ufo* pUfo) : ufo(pUfo) {}

UfoThread::~UfoThread() {
    if (flyThread && flyThread->joinable()) {
        flyThread->join();
    }
    delete flyThread;
}

void UfoThread::startUfo(const float x, const float y, const float height, const int speed) {
    if (flyThread != nullptr) {
        std::cout << "Es existiert schon ein flyThread!" << '\n';
        return;
    }

    // ✨ Hier sofort setzen
    isFlying = true;

    flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
}

bool UfoThread::getIsFlying() const {
    return isFlying;
}

void UfoThread::runner(const float x, const float y, const float height, const int speed) {
    ufo->flyToDest(x, y, height, speed);
    isFlying = false;
}
