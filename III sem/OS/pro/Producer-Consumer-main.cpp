#include <iostream>
#include <queue>
#include <thread>
#include <semaphore.h>

std::queue<int> buffer1;
sem_t emptySlots;
sem_t fullSlots;

void producer1() {
   for (int i = 1; i <= 5; ++i) {
      sem_wait(&emptySlots);
      buffer1.push((i));
      std::cout << "Produced ITEM: " << "p1->"<<(i) << std::endl;
      sem_post(&fullSlots);
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
   }
}

void producer2() {
   for (int i = 6; i <= 50; ++i) {
      sem_wait(&emptySlots);
      buffer1.push((i));
      std::cout << "Produced ITEM: " << "p2->"<<(i) << std::endl;
      sem_post(&fullSlots);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }
}

void consumer() {
   while (true) {
      sem_wait(&fullSlots);
      int data = buffer1.front();
      buffer1.pop();
      std::cout << "Consumed ITEM: " << data << std::endl;
      sem_post(&emptySlots);
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
   }
}

int main() {
   sem_init(&emptySlots, 0, 10);  // Maximum empty slots in the buffer
   sem_init(&fullSlots, 0, 0);   // Initially, no full slots in the buffer

   std::thread producer1Thread(producer1);
   std::thread producer2Thread(producer2);
   std::thread consumerThread(consumer);

   producer1Thread.join();
   producer2Thread.join();
   consumerThread.join();

   sem_destroy(&emptySlots);
   sem_destroy(&fullSlots);

   return 0;
}