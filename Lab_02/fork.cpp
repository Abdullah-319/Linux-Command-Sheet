#include<bits/stdc++.h>
#include<sys/wait.h>

using namespace std;

int main(){
pid_t process = fork();

char choice = 'y';

while (choice == 'y' || choice == 'Y')
{
if( process == 0){
cout<<"Child => pid:"<< getpid() << "ppid: " << getppid() << endl;
exit(EXIT_SUCCESS);
}
else if( process > 0){
cout<<"parent => pid:"<< getpid() << "ppid: " << getppid() << endl;
sleep(5);
cout<<"Child run successfully\n";
}else {
cout<<"Error creating child";
}

cout<<"Do you want to run another program (y/n)?? ";
cin>>choice;
}
return 0;
}
