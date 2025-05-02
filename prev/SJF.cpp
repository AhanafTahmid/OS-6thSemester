//5
//

#include<iostream>
using namespace std;
int main()
{
    
    int burstTime[20], process[20], waitingTime[20], tat[20], num;
    float avg_waitingTime = 0, avg_tat = 0, total = 0, totalTime = 0;
    cout<<" enter the number of process:";

    cin>> num;

    cout<<" \nenter the burst time:\n";

    for(int i=0; i<num; i++)
    {
        cout << "process" << i + 1 << ": ";
        cin >> burstTime[i];
        process[i] = i + 1;
    }

    for(int i=0; i<num; i)
    {
        for(int j=i+1; j<num; j++ )
        {
            if (burstTime[j] < burstTime[i])
            {
                swap(burstTime[i], burstTime[j]);
                swap(process[i], process[j]);
            }
        }
    }

    waitingTime[0] = 0;

    for (int i = 1; i < num; i++)
    {
        waitingTime[i] = 0;
        for (int j = 0; j < i; j++)
        {

            waitingTime[i] += burstTime[j];
        }

        total +=waitingTime[i];
    }
    avg_waitingTime = (float)total / num;

    cout << "\nProcess\t Burst Time \tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < num; i++)
    {

        tat[i] = burstTime[i] + waitingTime[i];

        totalTime += tat[i];
        cout << "process" << process[i] << "\t\t " << burstTime[i] << "\t\t " << waitingTime[i] << "\t\t " << tat[i] << endl;
    }
    avg_tat = (float)totalTime / num;
    cout << "\nAverage Waiting Time = " << avg_waitingTime << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;


}
