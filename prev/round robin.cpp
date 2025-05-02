/* depends on time quantam*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Total Number of Processes: ";
    cin >> n;

    int wait_time = 0, turnaround_time = 0;
    int arrival_time[n], burst_time[n], temp_burst_time[n];

    int x = n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details of Process " << i + 1 << "\n";
        cout << "Arrival Time: ";
        cin >> arrival_time[i];
        cout << "Burst Time: ";
        cin >> burst_time[i];
        temp_burst_time[i] = burst_time[i];
    }

    int time_quantum;
    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    int total = 0, counter = 0, i = 0;

    cout << "Process ID\tBurst Time\tTurnaround Time\tWaiting Time\n";

    for (total = 0, i = 0; x != 0;)
    {
        if (temp_burst_time[i] <= time_quantum && temp_burst_time[i] > 0)
        {
            total += temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        }
        else if (temp_burst_time[i] > 0)
        {
            temp_burst_time[i] -= time_quantum;
            total += time_quantum;
        }

        if (temp_burst_time[i] == 0 && counter == 1)
        {
            x--;
            cout << "Process No " << i + 1 << "\t\t" << burst_time[i] << "\t\t" << total - arrival_time[i] << "\t\t" << total - arrival_time[i] - burst_time[i] << endl;
            wait_time += total - arrival_time[i] - burst_time[i];
            turnaround_time += total - arrival_time[i];
            counter = 0;
        }

        if (i == n - 1)
        {
            i = 0;
        }
        else if (arrival_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = turnaround_time * 1.0 / n;

    cout << "\nAverage Waiting Time: " << average_wait_time << endl;
    cout << "Average Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}

