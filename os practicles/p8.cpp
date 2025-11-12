// Write a program to implement the SJF scheduling algorithm

// sjf.cpp
#include <bits/stdc++.h>
using namespace std;
struct Proc { int id, at, bt, ct, wt, tat; };

int main(){
    int n; cout << "Number of processes: "; cin >> n;
    vector<Proc> p(n);
    for (int i=0;i<n;++i) { p[i].id = i+1; cout << "AT BT for P" << i+1 << ": "; cin >> p[i].at >> p[i].bt; }
    int t=0, completed=0;
    vector<bool> done(n,false);
    double totwt=0, tottat=0;
    while (completed < n) {
        int idx=-1;
        int min_bt = INT_MAX;
        for (int i=0;i<n;++i){
            if (!done[i] && p[i].at <= t && p[i].bt < min_bt) {
                min_bt = p[i].bt; idx = i;
            }
        }
        if (idx == -1) { t++; continue; }
        t += p[idx].bt;
        p[idx].ct = t;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        totwt += p[idx].wt; tottat += p[idx].tat;
        done[idx] = true; completed++;
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x: p) cout << x.id << '\t' << x.at << '\t' << x.bt << '\t' << x.ct << '\t' << x.tat << '\t' << x.wt << '\n';
    cout << "Avg TAT: " << tottat/n << " Avg WT: " << totwt/n << '\n';
    return 0;
}
