/* depends on burst time
Turnaround time = WT + BT
aveaverage waiting time = total waiting time / no. of processes.
average turnaround time= total turnaround time / no. of processes
4 5 6 10
*/
#include <iostream>
using namespace std;

int main()
{
    int bt[20], pid[20], wt[20], tat[20], i, j, n, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "\nEnter Burst Time:\n";

    for (i = 0; i < n; i++)
    {
        cout << "pid" << i + 1 << ": ";
        cin >> bt[i];
        pid[i] = i + 1;
    }

    // Sorting of burst times
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;
    }

    wt[0] = 0;

    // Finding the waiting time of all the processes
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    // Average waiting time
    avg_wt = (float)total / n;

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        totalT += tat[i];
        cout << "pid" << pid[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    // Average turnaround time
    avg_tat = (float)totalT / n;

    cout << "\nAverage Waiting Time=" << avg_wt << endl;
    cout << "Average Turnaround Time=" << avg_tat << endl;

    return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
    int bt[20], pid[20], wt[20], tat[20], at[20], i, j, n, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "\nEnter Burst Time and Arrival Time:\n";

    for (i = 0; i < n; i++)
    {
        cout << "pid" << i + 1 << ": ";
        cin >> bt[i];
        cin >> at[i];
        pid[i] = i + 1;
    }

    // Sorting of processes based on burst time
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos] && at[j] <= at[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;
    }

    wt[0] = 0;

    // Finding the waiting time of all the processes
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        total += wt[i];
    }

    // Average waiting time
    avg_wt = (float)total / n;

    cout << "\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        totalT += tat[i];
        cout << "pid" << pid[i] << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    // Average turnaround time
    avg_tat = (float)totalT / n;

    cout << "\nAverage Waiting Time=" << avg_wt << endl;
    cout << "Average Turnaround Time=" << avg_tat << endl;

    return 0;
}


*/
