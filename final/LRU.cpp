#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

// 4 - frame
// 20 - pages
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
// Output
// Total Page Faults = 8

void solve() {
    int frame, pageCount;cin>>frame>>pageCount;
    vector<int> pages(pageCount);
    for(int &i: pages)cin >> i;
    unordered_map<int, list<int>::iterator> pageMap;
    list<int> cache; // Doubly linked list to store page order

    int page_faults = 0;

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];

        // If page is not in frame, we have a page fault
        if (pageMap.find(page) == pageMap.end()) {
            page_faults++;

            // If frame is full and not found, remove the least recently used page
            if (cache.size() == frame) {
                int last = cache.back(); // Least Recently Used
                cache.pop_back();
                pageMap.erase(last);
            }
        }
        else {
            // If page is in frame, delete the previous occurrence and 
            // move the current page to the front
            cache.erase(pageMap[page]);
        }

        cache.push_front(page);
        pageMap[page] = cache.begin();
    }

    cout << "Total Page Faults = " << page_faults << endl;
    cout << "Final Cache State (Most -> Least Recent): ";
    for (int page : cache) {
        cout << page << " ";
    }
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}