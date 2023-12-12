#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5

pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t chopstick[NUM_CHOPSTICKS];

void dine(int n);
int main() {
    int i, status_message;
    void* msg;

    // Initialize the mutexes for chopsticks
    for (i = 0; i < NUM_CHOPSTICKS; i++) {
        status_message = pthread_mutex_init(&chopstick[i], NULL);
        if (status_message != 0) {
            printf("\nMutex initialization failed");
            exit(1);
        }
    }

    // Create threads for philosophers
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        status_message = pthread_create(&philosopher[i], NULL, (void *)dine, (void *)(intptr_t)i);
        if (status_message != 0) {
            printf("\nThread creation error\n");
            exit(1);
        }
    }

    // Wait for all philosopher threads to finish
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        status_message = pthread_join(philosopher[i], &msg);
        if (status_message != 0) {
            printf("\nThread join failed\n");
            exit(1);
        }
    }

    // Destroy the mutexes for chopsticks (not necessary, but added for completeness)
    for (i = 0; i < NUM_CHOPSTICKS; i++) {
        status_message = pthread_mutex_destroy(&chopstick[i]);
        if (status_message != 0) {
            printf("\nMutex Destroyed\n");
            exit(1);
        }
    }

    return 0;
}

void dine(int n) {
    printf("\nPhilosopher %d is thinking", n);

    int left = n;
    int right = (n + 1) % NUM_PHILOSOPHERS;

    // Ensure philosophers always pick up chopsticks in a consistent order
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }

    // Pick up chopsticks
    pthread_mutex_lock(&chopstick[left]);
    pthread_mutex_lock(&chopstick[right]);

    printf("\nPhilosopher %d is eating", n);
    sleep(3);

    // Put down chopsticks
    pthread_mutex_unlock(&chopstick[right]);
    pthread_mutex_unlock(&chopstick[left]);

    printf("\nPhilosopher %d Finished eating", n);
}