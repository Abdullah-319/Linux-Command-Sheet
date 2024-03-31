#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {

	pid_t process = fork();
	
	if(process == 0) {
		cout<<"Running ls -l"<<endl;
		string inst = "ls -l";
		
		const char *cmd = inst.c_str();
		
		system(cmd);
		
		return 0;
	}
	else {
		wait(NULL);
	}

	return 0;

}
