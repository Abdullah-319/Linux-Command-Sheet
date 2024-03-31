#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {


	for(int i=0; i<5; i++) {
		pid_t process = fork();
		
		if(process == 0) {
			cout<<"Child=> pid="<<getpid()<<" ppid="<<getppid()<<endl;
			return 0;
		}
		else if(process > 0) {
			cout<<"Parent=> pid="<<getpid()<<" ppid="<<getppid()<<endl;
			wait(NULL);
		}
		else {
			cout<<"Error creating fork";
		}
	}

	

	return 0;

}
