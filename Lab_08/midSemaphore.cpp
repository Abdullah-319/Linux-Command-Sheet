#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

sem_t s1;
sem_t s2;
sem_t s3;
sem_t s4;

void * process_A(void *arg) {
    // Execute process A
    cout << "Process A executing." << endl;
    // Signal A finished
    sem_post(&s1);

    return nullptr;
}

void * process_B(void *arg) {
    sem_wait(&s1);  // Wait for A to finish
    // Execute process B
    cout << "Process B executing." << endl;
    // Signal B finished
    sem_post(&s2);

    return nullptr;
}

void * process_C(void *arg) {
    sem_wait(&s2);  // Wait for B to finish
    // Execute process C
    cout << "Process C executing." << endl;
    // Signal C finished
    sem_post(&s2);
    sem_post(&s1);

    return nullptr;
}

void * process_D(void *arg) {
    sem_wait(&s2);  // Wait for A to finish
    // Execute process D
    cout << "Process D executing." << endl;
    // Signal D finished
    sem_post(&s2);
    sem_post(&s3);

    return nullptr;
}

void * process_E(void *arg) {
    sem_wait(&s3);  // Wait for D to finish
    // Execute process E
    cout << "Process E executing." << endl;
    // Signal E finished
    sem_post(&s3);
    sem_post(&s4);

    return nullptr;
}

void * process_F(void *arg) {
    sem_wait(&s4);
    sem_wait(&s1);
    sem_wait(&s3);  // Wait for C or E to finish
    // Execute process F
    cout << "Process F executing." << endl;

    return nullptr;
}

int main() {
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 0);
    sem_init(&s4, 0, 0);

    pthread_t one, two, three, four, five, six;

    pthread_create(&one, NULL, process_A, NULL);
    pthread_create(&two, NULL, process_B, NULL);
    pthread_create(&three, NULL, process_C, NULL);
    pthread_create(&four, NULL, process_D, NULL);
    pthread_create(&five, NULL, process_E, NULL);
    pthread_create(&six, NULL, process_F, NULL);

    pthread_join(one, NULL);
    pthread_join(two, NULL);
    pthread_join(three, NULL);
    pthread_join(four, NULL);
    pthread_join(five, NULL);
    pthread_join(six, NULL);
    
    cout << "Inside MAIN." << endl;
   
    return 0;
}
