#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/utsname.h>   // For uname()

using namespace std;

int main() {
    struct utsname sysinfo;

    // --- Get Kernel Information using uname() ---
    if (uname(&sysinfo) == -1) {
        perror("uname");
        return 1;
    }

    cout << "---- Kernel Information ----" << endl;
    cout << "System Name : " << sysinfo.sysname << endl;
    cout << "Node Name   : " << sysinfo.nodename << endl;
    cout << "Release     : " << sysinfo.release << endl;
    cout << "Version     : " << sysinfo.version << endl;
    cout << "Machine     : " << sysinfo.machine << endl;

    // --- Get CPU Information from /proc/cpuinfo ---
    cout << "\n---- CPU Information ----" << endl;

    ifstream cpuinfo("/proc/cpuinfo");   // input file stream
    if (!cpuinfo) {
        cerr << "Error: Could not open /proc/cpuinfo" << endl;
        return 1;
    }

    string line;
    while (getline(cpuinfo, line)) {
        // print lines containing model name or vendor_id
        if (line.find("model name") == 0 || line.find("vendor_id") == 0) {
            cout << line << endl;
        }
    }

    cpuinfo.close();
    return 0;
}


