// fileinfo.cpp
// Write a program to print file details including owner access permissions, file access time, where
// file name is given as argument.


#include <iostream>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <iomanip>
#include <ctime>

using namespace std;

string perms(mode_t m) {
    string p;
    p += (m & S_IRUSR) ? 'r' : '-';
    p += (m & S_IWUSR) ? 'w' : '-';
    p += (m & S_IXUSR) ? 'x' : '-';
    p += (m & S_IRGRP) ? 'r' : '-';
    p += (m & S_IWGRP) ? 'w' : '-';
    p += (m & S_IXGRP) ? 'x' : '-';
    p += (m & S_IROTH) ? 'r' : '-';
    p += (m & S_IWOTH) ? 'w' : '-';
    p += (m & S_IXOTH) ? 'x' : '-';
    return p;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    struct passwd *pw = getpwuid(st.st_uid);
    struct group  *gr = getgrgid(st.st_gid);
    cout << "File: " << argv[1] << "\n";
    cout << "Size: " << st.st_size << " bytes\n";
    cout << "Owner UID: " << st.st_uid << " (" << (pw ? pw->pw_name : string("unknown")) << ")\n";
    cout << "Group GID: " << st.st_gid << " (" << (gr ? gr->gr_name : string("unknown")) << ")\n";
    cout << "Permissions: " << perms(st.st_mode) << "\n";
    cout << "Last access: " << std::put_time(std::localtime(&st.st_atime), "%c %Z") << "\n";
    cout << "Last modified: " << std::put_time(std::localtime(&st.st_mtime), "%c %Z") << "\n";
    return 0;
}
