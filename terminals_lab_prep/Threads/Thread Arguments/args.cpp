#include <bits/stdc++.h>
#include <thread>

using namespace std;

struct ThreadArgs {
	char title[100];
};

void* process(void* args) {
	ThreadArgs* threadArgs = (ThreadArgs*)args;
	cout<<"Thread title: "<< threadArgs->title << endl;
	return nullptr;
}

int main() {
	pthread_t t1, t2;
	
	ThreadArgs args1; // = ['Abdullah'];
	strcpy(args1.title, "Abdullah");
	
	ThreadArgs args2; // = ['Ahmad'];
	strcpy(args2.title, "Ahmad");
	
	pthread_create(&t1, NULL, process, (void*)&args1);
	pthread_create(&t2, NULL, process, (void*)&args2);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
