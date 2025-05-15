#pragma once
#include <thread>
#include <atomic>
#include "ufo.h"

class UfoThread {
private:
    std::thread* flyThread = nullptr;
    Ufo* ufo;
    std::atomic<bool> isFlying = false; // atomar für Thread-Sichtbarkeit
    void runner(const float x, const float y, const float height, const int speed);

public:
    UfoThread(Ufo* pUfo);
    ~UfoThread();
    void startUfo(const float x, const float y, const float height, const int speed);
    bool getIsFlying() const;
};
