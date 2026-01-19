#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

using namespace std;

// ---------- Multithreaded Application producer-consumer -----------------

// Shared resources
queue<int> buffer;
const int BUFFER_SIZE = 5;

// ii) Implement synchronization using mutexes and condition variables
// Synchronization primitives
mutex mtx;
condition_variable cv;

// Producer function
void producer() {
    for (int i = 1; i <= 10; i++) {
        unique_lock<mutex> lock(mtx);

        // Wait if buffer is full
        cv.wait(lock, []() {
            return buffer.size() < BUFFER_SIZE;
        });

        buffer.push(i);
        cout << "Produced: " << i << endl;

        lock.unlock();
        cv.notify_one();  // Notify consumer

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

// Consumer function
void consumer() {
    for (int i = 1; i <= 10; i++) {
        unique_lock<mutex> lock(mtx);

        // Wait if buffer is empty
        cv.wait(lock, []() {
            return !buffer.empty();
        });

        int item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << endl;

        lock.unlock();
        cv.notify_one();  // Notify producer

        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main() {
    // Create producer and consumer threads
    thread producer_thread (producer);
    thread consumer_thread (consumer);
    
    // Join threads
    producer_thread.join();
    consumer_thread.join();
    
    cout << "Processing complete." << endl;

    return 0;
}
