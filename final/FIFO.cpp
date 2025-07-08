#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// Input
// 3 - frame
// 15 - pages
// 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0
// Output
// 12 - page faults

void solve(){
    int frame, pageCount;cin>>frame>>pageCount;
    queue<int> fifoQueue; //page replacement queue
    unordered_set<int> pageInMemory; //pages in memory
    int pageFaults = 0;
    for (int i = 0; i < pageCount; i++){
        int page; cin >> page;
        // Check  page is not present in memory
        if (pageInMemory.find(page) == pageInMemory.end())
        {
            pageFaults++;
            // queue is full,page replacement kora
            if (fifoQueue.size() == frame){
                int victimPage = fifoQueue.front();
                fifoQueue.pop();
                pageInMemory.erase(victimPage);
            }
            fifoQueue.push(page);
            pageInMemory.insert(page);
        }
    }
    cout << "Total Page Faults: " << pageFaults << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}