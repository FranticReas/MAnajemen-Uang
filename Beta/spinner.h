#ifndef SPINNER_H
#define SPINNER_H

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

class Spinner {
public:
    Spinner() : running(false) {}

    void start() {
        running = true;
        spinnerThread = std::thread(&Spinner::spin, this);
    }

    void stop() {
        running = false;
        if (spinnerThread.joinable()) {
            spinnerThread.join();
        }
    }

private:
    std::atomic<bool> running;
    std::thread spinnerThread;

    void spin() {
        const char* spinnerChars = "|/-\\";
        int index = 0;

        while (running) {
            std::cout << "\r" << spinnerChars[index++ % 4] << " Loading..." << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }

        std::cout << "\r" << "           " << std::flush; // Clear the spinner line
    }
};

#endif // SPINNER_H
