#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

int main() {

	for(int i=0; i<5; i++) {
		
		pid_t process = fork();
		
		if(process == 0) {
			cout<<"Child process => pid: " << getpid() << ", ppid: " << getppid() << endl;
		}	
		else if(process > 0) {
			wait(NULL);
			exit(0);
		}
		else {
			cout<<"Error creating fork." << endl;
		}		
	}

	return 0;
}
