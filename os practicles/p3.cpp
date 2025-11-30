#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream meminfo("/proc/meminfo");
    if (!meminfo) {
        cerr << "Error: Unable to open /proc/meminfo" << endl;
        return 1;
    }

    string line;
    long memTotal = 0, memFree = 0, memAvailable = 0;

    while (getline(meminfo, line)) {
        istringstream iss(line);
        string key;
        long value;
        string unit;
        iss >> key >> value >> unit;

        if (key == "MemTotal:") memTotal = value;
        else if (key == "MemFree:") memFree = value;
        else if (key == "MemAvailable:") memAvailable = value;
    }

    cout << "===== Linux Kernel Memory Report =====" << endl;
    cout << "Configured (Total) Memory: " << memTotal / 1024 << " MB" << endl;
    cout << "Free Memory:               " << memFree / 1024 << " MB" << endl;
    cout << "Available Memory:          " << memAvailable / 1024 << " MB" << endl;
    cout << "======================================" << endl;

    return 0;
}
