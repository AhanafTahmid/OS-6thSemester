#include <iostream>
using namespace std;

int main() {
    int num_blocks, num_processes;
    cout << "\n\11tMemory Management Scheme - First Fit";

    cout << "Enter the number of blocks: ";
    cin >> num_blocks;

    cout << "Enter the number of processes: ";
    cin >> num_processes;

    int block_sizes[num_blocks];
    int process_sizes[num_processes];
    int allocation[num_processes];

    cout << "Enter the size of each block:\n";
    for (int i = 0; i < num_blocks; i++) {
        cin >> block_sizes[i];
    }

    cout << "Enter the size of each process:\n";
    for (int i = 0; i < num_processes; i++) {
        cin >> process_sizes[i];
    }

    // Initialize allocation array with -1 to indicate unallocated
    for (int i = 0; i < num_processes; i++) {
        allocation[i] = -1;
    }

    // First Fit Allocation
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_blocks; j++) {
            if (allocation[i] == -1 && block_sizes[j] >= process_sizes[i]) {
                allocation[i] = j;
                block_sizes[j] -= process_sizes[i];
                break;
            }
        }
    }

    // Display allocation details
    cout << "\nProcess\tSize\tBlock\n";
    for (int i = 0; i < num_processes; i++) {
        cout << i << "\t" << process_sizes[i] << "\t";
        if (allocation[i] != -1) {
            cout << allocation[i] << endl;
        } else {
            cout << "Not allocated" << endl;
        }
    }

    return 0;
}
