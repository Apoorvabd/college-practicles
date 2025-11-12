// optimal_page.cpp
// Write a program to implement Optimal scheduling algorithm.



#include <bits/stdc++.h>
using namespace std;

int main(){
    int frames;
    cout << "Number of frames: "; cin >> frames;
    cout << "Enter reference string length: ";
    int m; cin >> m;
    vector<int> ref(m);
    cout << "Enter reference string (space separated):\n";
    for (int i=0;i<m;++i) cin >> ref[i];

    set<int> s;
    vector<int> frame;
    int faults=0;
    for (int i=0;i<m;++i) {
        int page = ref[i];
        if (s.find(page) != s.end()) {
            cout << page << " -> Hit\n";
            continue;
        }
        faults++;
        if ((int)frame.size() < frames) {
            frame.push_back(page);
            s.insert(page);
        } else {
            // find page in frame with farthest next use (or not used again)
            int idxToReplace = -1;
            int farthest = i+1;
            for (int j=0;j<frames;++j) {
                int p = frame[j];
                int k;
                for (k=i+1;k<m;++k) if (ref[k]==p) break;
                if (k==m) { idxToReplace = j; break; } // not used again
                if (k > farthest) { farthest = k; idxToReplace = j; }
            }
            if (idxToReplace == -1) idxToReplace = 0;
            s.erase(frame[idxToReplace]);
            frame[idxToReplace] = page;
            s.insert(page);
        }
        cout << page << " -> Fault, Frames: ";
        for (int x: frame) cout << x << ' ';
        cout << '\n';
    }
    cout << "Total page faults: " << faults << '\n';
    return 0;
}
