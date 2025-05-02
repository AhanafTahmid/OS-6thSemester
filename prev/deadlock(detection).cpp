#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> max_demand(n, vector<int>(m));
    vector<int> available(m);
    vector<int> work(available);
    vector<bool> finish(n, false);
    vector<int> safe_sequence;

    // Input Allocation Matrix
    cout << "Enter the Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    // Input Max Demand Matrix
    cout << "Enter the Maximum Demand Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max_demand[i][j];
        }
    }

    // Input Available Vector
    cout << "Enter the Available Vector:\n";
    for (int i = 0; i < m; i++) {
        cin >> available[i];
        work[i] = available[i];
    }

    // Calculate the Need Matrix
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max_demand[i][j] - allocation[i][j];
        }
    }

    // Banker's Algorithm
    bool deadlock_detected = false;
    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }

                if (can_allocate) {
                    finish[i] = true;
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence.push_back(i);
                    count++;
                    found = true;
                }
            }
        }

        if (!found) {
            deadlock_detected = true;
            break;
        }
    }

    if (deadlock_detected) {
        cout << "Deadlock detected! System is not in a safe state." << endl;
    } else {
        cout << "System is in a safe state. Safe sequence: ";
        for (int i = 0; i < n; i++) {
            cout << "P" << safe_sequence[i];
            if (i < n - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}
