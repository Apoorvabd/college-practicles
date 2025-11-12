// 12. Write a program to implement first-fit, best-fit and worst-fit allocation strategies.

// fit_alloc.cpp
#include <bits/stdc++.h>
using namespace std;

void allocate(vector<int> blocks, vector<int> procs, string mode) {
    int m = blocks.size(), n = procs.size();
    vector<int> alloc(n, -1);
    if (mode == "first") {
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (blocks[j] >= procs[i]) { alloc[i]=j; blocks[j]-=procs[i]; break; }
            }
        }
    } else if (mode == "best") {
        for (int i=0;i<n;i++){
            int best = -1;
            for (int j=0;j<m;j++){
                if (blocks[j] >= procs[i]) {
                    if (best == -1 || blocks[j] < blocks[best]) best = j;
                }
            }
            if (best != -1) { alloc[i] = best; blocks[best] -= procs[i]; }
        }
    } else if (mode == "worst") {
        for (int i=0;i<n;i++){
            int worst = -1;
            for (int j=0;j<m;j++){
                if (blocks[j] >= procs[i]) {
                    if (worst == -1 || blocks[j] > blocks[worst]) worst = j;
                }
            }
            if (worst != -1) { alloc[i] = worst; blocks[worst] -= procs[i]; }
        }
    }
    cout << mode << " fit allocation results:\n";
    cout << "Proc\tSize\tBlock\n";
    for (int i=0;i<n;i++){
        cout << "P" << i+1 << "\t" << procs[i] << "\t";
        if (alloc[i] != -1) cout << alloc[i] << " (remaining block size " << blocks[alloc[i]] << ")\n";
        else cout << "Not allocated\n";
    }
    cout << "----\n";
}

int main(){
    int m,n;
    cout << "Number of memory blocks: "; cin >> m;
    vector<int> blocks(m);
    cout << "Enter block sizes:\n";
    for (int i=0;i<m;i++) cin >> blocks[i];
    cout << "Number of processes: "; cin >> n;
    vector<int> procs(n);
    cout << "Enter process sizes:\n";
    for (int i=0;i<n;i++) cin >> procs[i];

    allocate(blocks, procs, "first");
    allocate(blocks, procs, "best");
    allocate(blocks, procs, "worst");
    return 0;
}
