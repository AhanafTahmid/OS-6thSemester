//Round Robin
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<array<int, 3>> v = {
        {0, 5, 1}, // {arrival_time, burst_time, process_id}
        {1, 3, 2},
        {2, 8, 3},
        {3, 6, 4}
    };

    int time_quantum = 2;

    // Sort by arrival time
    sort(v.begin(), v.end());

    int n = v.size();
    vector<int> remaining(n);
    for (int i = 0; i < n; ++i) remaining[i] = v[i][1];

    vector<array<int, 3>> a; // {process_id, start_time, end_time}
    queue<int> q;
    int current_time = 0, idx = 0;

    while (!q.empty() || idx < n) {
        // Add all processes that have arrived to the queue
        while (idx < n && v[idx][0] <= current_time) {
            q.push(idx);
            idx++;
        }

        if (q.empty()) {
            // CPU is idle
            a.push_back({-1, current_time, v[idx][0]});
            current_time = v[idx][0];
            continue;
        }

        int i = q.front(); q.pop();
        int exec_time = min(time_quantum, remaining[i]);
        a.push_back({v[i][2], current_time, current_time + exec_time});
        current_time += exec_time;
        remaining[i] -= exec_time;

        // Check for new arrivals during execution
        while (idx < n && v[idx][0] <= current_time) {
            q.push(idx);
            idx++;
        }

        if (remaining[i] > 0) {
            q.push(i); // Add back to queue if not finished
        }
    }

    // Output
    for (auto x : a) {
        if (x[0] == -1)
            cout << "IDLE " << x[1] << " " << x[2] << endl;
        else
            cout << "P" << x[0] << " " << x[1] << " " << x[2] << endl;
    }

    return 0;
}