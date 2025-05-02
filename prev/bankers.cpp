/*
Enter the number of processes: 5
Enter the number of resources: 3

Enter the Allocation Matrix:
1 2 2
1 0 3
1 2 1
0 2 0
0 2 1

Enter the Maximum Demand Matrix:
3 3 2
1 2 3
1 3 5
0 3 2
0 3 3

Enter the Available Vector:
0 0 0

*/

#include <iostream>
using namespace std;

int main()
{
    int n, m, i, j, k, y, ind = 0;
    cout << "Enter the number of Processes: ";
    cin >> n;
    cout << "Enter the number of Resources: ";
    cin >> m;

    int alloc[20][20], max[20][20], avail[50];

    cout << "Enter the Allocation Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the Max Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "Enter the Available Matrix:\n";
    for (i = 0; i < m; i++)
    {
        cin >> avail[i];
    }

    int finish[n], safesequence[n], work[m], need[n][m];

    // Calculating NEED matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    cout << "NEED matrix is:\n";
    for (i = 0; i < n; i++)
    {
        cout << "\n";
        for (j = 0; j < m; j++)
        {
            cout << " " << need[i][j] << " ";
        }
    }

    for (i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safesequence[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        work[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    cout << "\nFollowing is the SAFE Sequence: ";
    for (i = 0; i < n; i++)
    {
        cout << "P" << safesequence[i] << " ";
    }

    return 0;
}

