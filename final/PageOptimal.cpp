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
    int frame, pageCount; cin >> frame >> pageCount;
    vector<int> pages(pageCount);
    for (int &i : pages) cin >> i;

    vector<int> frames; // current pages in frame
    int page_faults = 0;

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];

        // If page NOT in frame => page fault
        if (find(frames.begin(), frames.end(), page) == frames.end()) {
            page_faults++; // increment page fault

            // If frame has space, just add page
            if (frames.size() < frame) {
                frames.push_back(page);
                continue;
            }

            // Frame full => replace using optimal
            int index_to_replace = -1;
            int farthest = i + 1;

            for (int j = 0; j < frame; j++) {
                int k;
                for (k = i + 1; k < pageCount; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            index_to_replace = j;
                        }
                        break;
                    }
                }
                // If page is never used again, replace immediately
                if (k == pageCount) {
                    index_to_replace = j;
                    break;
                }
            }
            frames[index_to_replace] = page;
        }
    }

    cout << "Total Page Faults = " << page_faults << endl;
    // cout << "Final Frame State: ";
    // for (int p : frames) cout << p << " ";
    // cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
