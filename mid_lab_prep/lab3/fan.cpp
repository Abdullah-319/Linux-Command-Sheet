#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {

	int processes;
	
	cout<<"Enter no. of process you wanna create: ";
	cin>>processes;
	
	if(processes < 1) {
		cout<<"Enter +ve interger";
		return 0;
	}

	
	
	for(int i=0; i<processes; i++) {
	
	pid_t process = fork();
	
		if(process == 0) {
			cout<<"Child=> pid="<<getpid()<<" ppid="<<getppid()<<endl;
			return 0;
		}
	}
	
	
	for(int i=0; i<processes; i++) {
		wait(NULL);
	}

	return 0;

}
