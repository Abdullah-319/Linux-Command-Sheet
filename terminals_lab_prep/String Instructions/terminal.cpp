#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

int main() {

	pid_t process = fork();
	
	if(process == 0) {
		cout<<"Child=> pid: "<< getpid() << ", ppid: "<< getppid()<< endl;
		string instruction = "ls -l";
		
		const char *cmd = instruction.c_str();
		system(cmd);
	}
	else if(process > 0) {
		wait(NULL);
	}
	else {
		cout << "Error creating child";
	}

	return 0;
}
