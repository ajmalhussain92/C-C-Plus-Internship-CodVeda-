#include <iostream>
#include <pthread.h>	// i) POSIX thread
#include <unistd.h>   	// for sleep()
#define BUFFER_SIZE 5
using namespace std;

// ---------- Multithreaded Application producer-consumer using POSIX Thread -----------------

int buffer[BUFFER_SIZE];
int in = 0, out = 0, count = 0;

// ii) Implement synchronization using mutexes and condition variables
// Synchronization objects
pthread_mutex_t mutex;
pthread_cond_t notFull;
pthread_cond_t notEmpty;

// Producer thread function
void* producer (void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock (&mutex);

        // Wait if buffer is full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait (&notFull, &mutex);
        }

        buffer[in] = i;
        cout << "Produced: " << buffer[in] << endl;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        pthread_cond_signal (&notEmpty);
        pthread_mutex_unlock (&mutex);

        sleep(1);
    }
    return nullptr;
}

// Consumer thread function
void* consumer (void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock (&mutex);

        // Wait if buffer is empty
        while (count == 0) {
            pthread_cond_wait (&notEmpty, &mutex);
        }

        int item = buffer[out];
        cout << "Consumed: " << item << endl;
        out = (out + 1) % BUFFER_SIZE;
        count--;

        pthread_cond_signal (&notFull);
        pthread_mutex_unlock (&mutex);

        sleep(1);
    }
    return nullptr;
}

int main() {
    pthread_t prodThread, consThread;

    // Initialize mutex and condition variables
    pthread_mutex_init (&mutex, nullptr);
    pthread_cond_init (&notFull, nullptr);
    pthread_cond_init (&notEmpty, nullptr);

    // Create threads
    pthread_create (&prodThread, nullptr, producer, nullptr);
    pthread_create (&consThread, nullptr, consumer, nullptr);

    // Wait for threads to finish
    pthread_join (prodThread, nullptr);
    pthread_join (consThread, nullptr);

    // Destroy synchronization objects
    pthread_mutex_destroy (&mutex);
    pthread_cond_destroy (&notFull);
    pthread_cond_destroy (&notEmpty);

    return 0;
}
