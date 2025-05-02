/* depends on arival time
Find waiting time for all other processes i.e. for
process i ->
wt[i] = bt[i-1] + wt[i-1] .
Find turnaround time = waiting_time + burst_time
for all processes.
Find average waiting time =
total_waiting_time / no_of_processes.
Similarly, find average turnaround time =
total_turn_around_time / no_of_processes.
3 5 7, 3 4 9
*/

#include <iostream>
using namespace std;

int main()
{
    int pid[15];  // process id
    int bt[15];   // burst time
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter process id of all the processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pid[i];
    }
    cout << "Enter burst time of all the processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    int i, wt[15];             //waiting time
    wt[0] = 0;
    // for calculating waiting time of each process
    for (i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    cout << "Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n";
    float twt = 0.0;
    float tat = 0.0;
    for (i = 0; i < n; i++)
    {
        cout << pid[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << bt[i] + wt[i] << "\n";
        // for calculating total waiting time
        twt += wt[i];
        // for calculating total turnaround time
        tat += (wt[i] + bt[i]);
    }
    float att, awt;
    // for calculating average waiting time
    awt = twt / n;
    // for calculating average turnaround time
    att = tat / n;
    cout << "Avg. waiting time= " << awt << "\n";
    cout << "Avg. turnaround time= " << att;

    }
