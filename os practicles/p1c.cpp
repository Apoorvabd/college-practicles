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
        cout << "Child Process (PID = " << getpid() << ") is running..." << endl;
        sleep(2); // child ko thoda kaam karne do (2 sec)
        cout << "Child Process finished its task." << endl;
    } 
    else {
        // Parent process
        cout << "Parent waiting for child (PID = " << pid << ")..." << endl;
        wait(NULL); // wait for child to finish
        cout << "Parent Process resumes after child completion." << endl;
    }

    return 0;
}