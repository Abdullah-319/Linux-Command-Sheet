#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

int main() {

	char choice = 'y';
	
	pid_t process = fork();
	
	while(choice == 'y' || choice == 'Y') {
		
		if(process == 0) {
			cout<<"Child Process => pid: "<< getpid() << " ,ppid => " << getppid() << endl;
			exit(EXIT_SUCCESS);
		}	
		else if (process > 0) {
			cout<<"Parent Process => pid: " << getpid() << " ,ppid => " << getppid() << endl;
			sleep(2);
			cout<<"Child run successfully!" << endl; 
		}	
		else {
			cout<<"Error creating child" << endl;
		}
		
		cout<<"Do you want to run another program (y/n)?? ";
		cin>>choice;
		
	}

	return 0;
}
