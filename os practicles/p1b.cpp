#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed!" << endl;
    } 
    else if (pid == 0) {
        // Child process
        cout << "Child Process: PID = " << getpid() 
             << ", Parent PID = " << getppid() << endl;
        cout << "Child is executing its own code." << endl;
    } 
    else {
        // Parent process
        cout << "Parent Process: PID = " << getpid() 
             << ", Child PID = " << pid << endl;
        cout << "Parent is executing its own code." << endl;
    }

    return 0;
}