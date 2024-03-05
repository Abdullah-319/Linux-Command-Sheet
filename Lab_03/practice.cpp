#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

int main() {


for(int i=0; i<5; i++) {
    pid_t child_fork = fork();

    if(child_fork == 0) {
        cout<<"child => pid: "<<getpid()<<" ,ppid: "<<getppid()<<endl;
        exit(0);
    }
    else if(child_fork > 0) {
        cout<<"parent => pid: "<<getpid()<<" ,ppid: "<<getppid()<<endl;
        wait(NULL);
    }
    else {
        cout<<"Error"<<endl;
    }
}

for(int i=0; i<5; i++) {
    wait(NULL);
}
return 0;
}