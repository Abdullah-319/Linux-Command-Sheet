#include <iostream>
#include <sys/wait.h>
#include <bits/stdc++.h>

using namespace std;

// Function to generate random number between 0 and 10
int generateRandomNumber() {
    srand(time(nullptr));
    return rand() % 11;
}

// Function for each child process
void childProcess(int id, int pipefd[]) {
    close(pipefd[0]); // Close the read end of the pipe

    int randomNumber = generateRandomNumber();
    int turns = 0;
    int guess;

    cout << "Child " << id << " generated a random number between 0 and 10." << endl;

    do {
        cout << "Enter your guess for Child " << id << ": ";
        cin >> guess;
        write(pipefd[1], &guess, sizeof(guess));
        turns++;
    } while (guess != randomNumber);

    cout << "Congratulations! You guessed the number in " << turns << " turns." << endl;

    close(pipefd[1]); // Close the write end of the pipe
    exit(turns);
}

int main() {
    const int numChildren = 3;
    int turns[numChildren];
    int pipefd[numChildren][2];
    pid_t pid[numChildren];

    // Create pipes
    for (int i = 0; i < numChildren; i++) {
        if (pipe(pipefd[i]) == -1) {
            cerr << "Pipe failed" << endl;
            return 1;
        }
    }

    // Create child processes
    for (int i = 0; i < numChildren; i++) {
        pid[i] = fork();
        if (pid[i] == 0) { // Child process
            childProcess(i+1, pipefd[i]);
        } else if (pid[i] < 0) { // Error handling
            cerr << "Fork failed" << endl;
            return 1;
        }
    }

    // Parent process
    for (int i = 0; i < numChildren; i++) {
        close(pipefd[i][1]); // Close the write end of the pipes
        waitpid(pid[i], &turns[i], 0); // Wait for child processes to finish and get the number of turns
        read(pipefd[i][0], &turns[i], sizeof(turns[i]));
        close(pipefd[i][0]); // Close the read end of the pipes
    }

    // Determine winner
    int minTurns = turns[0];
    int winner = 0;
    for (int i = 1; i < numChildren; i++) {
        if (turns[i] < minTurns) {
            minTurns = turns[i];
            winner = i;
        }
    }

    cout << "Child " << winner + 1 << " wins with " << minTurns << " turns!" << endl;

    return 0;
}
