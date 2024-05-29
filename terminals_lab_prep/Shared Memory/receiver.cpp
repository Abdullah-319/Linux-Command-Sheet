#include <bits/stdc++.h>
#include <sys/shm.h>

using namespace std;

int main() {

	int shmid;
	void* shared_memory;
	
	shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
	cout<<"Shared memory id is: " << shmid << endl;
	
	shared_memory = shmat(shmid, NULL, 0);
	cout<<"Process attached is: "<<shared_memory<<endl;
	
	cout<<"Sender sent you this: "<< endl;
	cout<<(char*)shared_memory;
	
	return 0;
}
