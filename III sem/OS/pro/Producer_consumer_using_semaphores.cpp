#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>

const int bufferSize = 5;
std::vector<int> buffer(bufferSize);
std::size_t in = 0, out = 0;

std::counting_semaphore empty(bufferSize);
std::counting_semaphore full(0);
std::binary_semaphore mutex(1);

void producer(int id) {
    for (int i = 0; i < 10; ++i) {
        int item = i + (id * 10);
        empty.acquire();  // Decrement empty slots
        mutex.acquire();  // Acquire the buffer lock

        buffer[in] = item;
        in = (in + 1) % bufferSize;

        std::cout << "Producer " << id << " produced: " << item << std::endl;

        mutex.release();  // Release the buffer lock
        full.release();   // Increment full slots
    }
}

void consumer(int id) {
    for (int i = 0; i < 10; ++i) {
        full.acquire();   // Decrement full slots
        mutex.acquire();  // Acquire the buffer lock

        int item = buffer[out];
        out = (out + 1) % bufferSize;

        std::cout << "Consumer " << id << " consumed: " << item << std::endl;

        mutex.release();  // Release the buffer lock
        empty.release();  // Increment empty slots
    }
}

int main() {
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    for (int i = 0; i < 3; ++i) {
        producers.emplace_back(producer, i);
        consumers.emplace_back(consumer, i);
    }

    for (int i = 0; i < 3; ++i) {
        producers[i].join();
        consumers[i].join();
    }

    return 0;
}
