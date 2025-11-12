// Write a program to calculate sum of n numbers using thread library.

// srjf.cpp
#include <bits/stdc++.h>
using namespace std;
struct Proc { int id, at, bt, rem, ct, wt, tat; };

int main(){
    int n; cout << "Number of processes: "; cin >> n;
    vector<Proc> p(n);
    for (int i=0;i<n;++i) { p[i].id = i+1; cout << "AT BT for P" << i+1 << ": "; cin >> p[i].at >> p[i].bt; p[i].rem = p[i].bt; }
    int t=0, completed=0;
    double totwt=0, tottat=0;
    int last = -1;
    while (completed < n) {
        int idx = -1; int mn = INT_MAX;
        for (int i=0;i<n;++i) if (p[i].at <= t && p[i].rem > 0 && p[i].rem < mn) { mn = p[i].rem; idx = i; }
        if (idx == -1) { t++; continue; }
        // execute for 1 unit (time quantum = 1)
        p[idx].rem--; t++;
        if (p[idx].rem == 0) {
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            totwt += p[idx].wt; tottat += p[idx].tat;
            completed++;
        }
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x: p) cout << x.id << '\t' << x.at << '\t' << x.bt << '\t' << x.ct << '\t' << x.tat << '\t' << x.wt << '\n';
    cout << "Avg TAT: " << tottat/n << " Avg WT: " << totwt/n << '\n';
    return 0;
}
