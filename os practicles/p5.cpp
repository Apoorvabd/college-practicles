// copy_syscall.cpp
// Write a program to copy files using system calls.


#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source> <dest>\n";
        return 1;
    }
    const char* src = argv[1];
    const char* dst = argv[2];

    int infd = open(src, O_RDONLY);
    if (infd < 0) { perror("open src"); return 1; }

    struct stat st;
    if (fstat(infd, &st) < 0) { perror("fstat"); close(infd); return 1; }

    int outfd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & 0777);
    if (outfd < 0) { perror("open dst"); close(infd); return 1; }

    const size_t BUF_SZ = 8192;
    char buf[BUF_SZ];
    ssize_t n;
    while ((n = read(infd, buf, BUF_SZ)) > 0) {
        ssize_t w = 0;
        while (w < n) {
            ssize_t written = write(outfd, buf + w, n - w);
            if (written < 0) { perror("write"); close(infd); close(outfd); return 1; }
            w += written;
        }
    }
    if (n < 0) { perror("read"); }
    close(infd);
    close(outfd);
    return (n < 0) ? 1 : 0;
}
