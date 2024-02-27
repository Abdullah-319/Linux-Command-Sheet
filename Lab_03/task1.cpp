#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    int no_of_processes;
    cout<< "How many processes you wanna create: ";
    cin>>no_of_processes;

    if (no_of_processes <= 0)
    {
        cerr << "Please enter a positive integer." << endl;
        return -1;
    }

    cout << "Creating " << no_of_processes << " processes " << endl;

    for (int i = 0; i < no_of_processes; ++i)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            cout << "Failed to fork process." << endl;
            return 1;
        }
        else if (pid == 0)
        {
            cout << "Child process with PID: " << getpid() << ", Parent PID: " << getppid() << endl;
        }
        else
        {               
            wait(NULL); 
            exit(0);    
        }
    }

    return 0;
}
