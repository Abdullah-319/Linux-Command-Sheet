#include <bits/stdc++.h>
#include <sys/shm.h>

using namespace std;

int main() {
    int shmid;
    void* shared_memory;
    cahr input[100];

    shmid = shmget((key_t)1234, 1024, 0666);

    cout<<"Id of shared memory is: "<<shmid<<endl;

    shared_memory = shmat(shmid, NULL, 0);

    cout<<"Process attached is: "<< shared_memory <<endl;

    cout<<"Enter Data you want to send: " << endl;

    cin.getline(input, 100);

    stcpy(static_cast<char *>(shared_memory), input);

    return 0;
}