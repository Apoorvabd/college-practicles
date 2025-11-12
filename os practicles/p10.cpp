// Write a program to implement SRJF scheduling algorithm

// srjf.cpp
// sum_threads.cpp
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

struct Args {
    long long *arr;
    int start, end;
    long long partial;
};

void* worker(void* arg) {
    Args* a = (Args*)arg;
    long long s = 0;
    for (int i = a->start; i < a->end; ++i) s += a->arr[i];
    a->partial = s;
    return nullptr;
}

int main(){
    int n, t;
    cout << "Enter n (count of numbers): "; cin >> n;
    vector<long long> arr(n);
    cout << "Enter numbers:\n";
    for (int i=0;i<n;++i) cin >> arr[i];
    cout << "Number of threads: "; cin >> t;
    if (t <= 0) t = 1;
    if (t > n) t = n;
    vector<Args> args(t);
    vector<pthread_t> threads(t);
    int per = n / t;
    int rem = n % t;
    int idx = 0;
    for (int i=0;i<t;++i) {
        int start = idx;
        int cnt = per + (i < rem ? 1 : 0);
        int end = start + cnt;
        args[i].arr = arr.data();
        args[i].start = start;
        args[i].end = end;
        args[i].partial = 0;
        pthread_create(&threads[i], nullptr, worker, &args[i]);
        idx = end;
    }
    long long total = 0;
    for (int i=0;i<t;++i) {
        pthread_join(threads[i], nullptr);
        total += args[i].partial;
    }
    cout << "Total sum = " << total << "\n";
    return 0;
}
