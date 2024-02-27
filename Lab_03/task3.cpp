#include <bits/stdc++.h>
#include <sys/wait.h>

using namespace std;

int main()
{

    pid_t pid = fork();

    if (pid < 0)
    {
        cout << "Failed to create fork";
        return 1;
    }
    else if (pid == 0)
    {
        cout << "Child PID = " << getpid() << "  ,Parent PPID: " << getppid() << endl;
        string instruction = "ls -l";
        const char *command = instruction.c_str();
        system(command);
        return 1;
    }
    else
    {

        wait(NULL);
    }

    return 0;
}