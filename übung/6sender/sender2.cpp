#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <mutex>

std::mutex mtx;

class Sender
{
private:
    int number;
    int countdown;
    std::mt19937 r;
    std::thread senderThread;

    void run()
    {
        while (true)
        {
            {
                std::lock_guard<std::mutex> lock(mtx);  // sicheres Locking

                if (countdown < 0) break;

                std::cout << "\nsending message " << number << ": ";
                for (int i = countdown; i >= 0; i--)
                {
                    std::cout << number << " ";
                    std::this_thread::sleep_for(std::chrono::milliseconds(r() % 200));
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(r() % 200));
            break; // sonst Endlosschleife
        }
    }

public:
    Sender(const int pNumber, const int pCountdown)
        : number(pNumber), countdown(pCountdown)
    {
        senderThread = std::thread(&Sender::run, this);
    }

    ~Sender()
    {
        if (senderThread.joinable())
            senderThread.join();
    }
};

int main()
{
    Sender sender1(1, 20);
    Sender sender2(2, 20);
    return 0;
}
