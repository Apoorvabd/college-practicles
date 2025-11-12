#include <iostream>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()

using namespace std;

int main() {
    pid_t pid = fork(); // create child process

    if (pid < 0) {
        cout << "Fork failed!" << endl;
    } 
    else {
        cout << "This is process with PID = " << getpid() << endl;
    }

    return 0;
}
