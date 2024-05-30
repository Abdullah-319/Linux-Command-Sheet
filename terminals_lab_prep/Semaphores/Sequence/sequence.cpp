#include <bits/stdc++.h>
#include <thread>
#include <semaphore.h>

using namespace std;

void* seq(void* args) {
	for(int i=21; i<=25; i++){
		cout<<i<<endl;
		sleep(1);
	}
	
	return nullptr;
}

int main() {
	pthread_t t1;	
	
	pthread_create(&t1, NULL, seq, NULL);
	
	for(int i=1; i<=5; i++) {
		cout<<i<<endl;
		sleep(1);
	}
	
	pthread_join(t1, NULL);

	return 0;
}
