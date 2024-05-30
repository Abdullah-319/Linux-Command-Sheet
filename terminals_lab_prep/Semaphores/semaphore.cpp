#include <bits/stdc++.h>
#include <thread>
#include <semaphore.h> 

using namespace std;

sem_t s1;
sem_t s2;

void* processA(void* args) {
	sem_wait(&s2);
	// Execute process A
	cout<<"Process A running..."<<endl;
	//Signal A finished
	sem_post(&s1);
	
	return nullptr;
}

void* processB(void* args) {
	sem_wait(&s1);
	// Execute process B
	cout<<"Process B running..."<<endl;
	//Signal B finished
	sem_post(&s2);
	
	return nullptr;
}


int main() {
	sem_init(&s1, 0, 1);
	sem_init(&s2, 0, 0);
	
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, processA, NULL);
	pthread_create(&t2, NULL, processB, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	cout<<"Inside MAIN..."<<endl;

	return 0;
}
