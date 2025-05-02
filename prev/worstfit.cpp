#include <iostream>
using namespace std;

int main() {
    int fragment[20] = {0}, b[20], p[20], barray[20] = {0}, parray[20] = {0};
    int nb, np, temp, highest;

    cout << "\n\t\t\tMemory Management Scheme - Worst Fit" << endl;
    cout << "Enter the number of blocks: ";
    cin >> nb;

    cout << "Enter the number of processes: ";
    cin >> np;

    cout << "\nEnter the size of the blocks:\n";
    for (int i = 0; i < nb; i++) {
        cout << "Block no." << i + 1 << ": ";
        cin >> b[i];
    }

    cout << "\nEnter the size of the processes:\n";
    for (int i = 0; i < np; i++) {
        cout << "Process no." << i + 1 << ": ";
        cin >> p[i];
    }

    for (int i = 0; i < np; i++) {
        highest = -1;
        for (int j = 0; j < nb; j++) {
            if (barray[j] != 1) {
                temp = b[j] - p[i];
                if (temp >= 0 && highest < temp) {
                    parray[i] = j;
                    highest = temp;
                }
            }
        }
        fragment[i] = highest;
        barray[parray[i]] = 1;
    }

    cout << "\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n";
    for (int i = 0; i < np; i++) {
        cout << i + 1 << "\t\t" << p[i] << "\t\t" << parray[i] + 1 << "\t\t" << b[parray[i]] << "\t\t" << fragment[i] << endl;
    }

    return 0;
}
