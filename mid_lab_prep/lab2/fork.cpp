#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

int main() {

	char choice = 'y';
	
	pid_t process = fork();
	
	while(choice == 'y' || choice == 'Y') {
	
	
		if(process == 0) {
		
			cout<<"Child=> pid="<<getpid()<<" ppid="<<getppid()<<endl;
			return 0;
		}
		else if(process > 0) {
			cout<<"Parent=> pid="<<getpid()<<" ppid="<<getppid()<<endl;
			sleep(1);
		}
		else {
			cout<<"Failed to create a fork"<<endl;
		}
	
	
		cout<<"Do you want to re run the process? (y/n)";
		cin>>choice;
	
	}

	return 0;

}
