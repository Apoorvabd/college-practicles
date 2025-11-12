// Write a program to implement FCFS scheduling algorithm.

// fcfs.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Number of processes: ";
    if (!(cin >> n)) return 0;
    struct P { int id; int at; int bt; int ct, wt, tat; };
    vector<P> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].id = i+1;
        cout << "Arrival time and Burst time for P" << a[i].id << ": ";
        cin >> a[i].at >> a[i].bt;
    }
    sort(a.begin(), a.end(), [](const P& x,const P& y){ return x.at < y.at; });
    int time = 0;
    double total_wt=0, total_tat=0;
    for (auto &p : a) {
        if (time < p.at) time = p.at;
        time += p.bt;
        p.ct = time;
        p.tat = p.ct - p.at;
        p.wt  = p.tat - p.bt;
        total_wt += p.wt;
        total_tat += p.tat;
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &p : a) cout << p.id << '\t' << p.at << '\t' << p.bt << '\t' << p.ct << '\t' << p.tat << '\t' << p.wt << '\n';
    cout << "Avg TAT = " << total_tat/n << ", Avg WT = " << total_wt/n << endl;
    return 0;
}
