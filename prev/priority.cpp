/*higher num represented higher priority */
#include <iostream>
using namespace std;

int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, pos, temp;
    double avg_wt, avg_tat, total = 0;

    cout << "Enter Total Number of Processes: ";
    cin >> n;
    cout << "\nEnter Burst Time and Priority:\n";

    for (i = 0; i < n; i++)
    {
        cout << "\nP[" << i + 1 << "]\n";
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority: ";
        cin >> pr[i];
        p[i] = i + 1; // contains process number
    }

    // Sorting burst time, priority, and process number
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0; // waiting time for the first process is zero

    // Calculate waiting time
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    avg_wt = total / n; // average waiting time
    total = 0;

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // calculate turnaround time
        total += tat[i];
        cout << "\nP[" << p[i] << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

    avg_tat = total / n;

    cout << "\n\nAverage Waiting Time=" << avg_wt;
    cout << "\nAverage Turnaround Time=" << avg_tat;

    return 0;
}
