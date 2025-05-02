#include <iostream>
using namespace std;

int main()
{
    int fragment[20] = {0}, b[20], p[20], barray[20] = {0}, parray[20] = {0};
    int nb, np, temp, lowest;

    cout << "\n\t\t\tMemory Management Scheme - Best Fit" << endl;

    cout << "Enter the number of blocks:";
    cin >> nb;

    cout << "Enter the number of processes:";
    cin >> np;

    cout << "\nEnter the size of the blocks:\n";
    for (int i = 0; i < nb; i++)
    {
        cout << "Block no." << i + 1 << ":";
        cin >> b[i];
    }

    cout << "\nEnter the size of the processes:\n";
    for (int i = 0; i < np; i++)
    {
        cout << "Process no." << i + 1 << ":";
        cin >> p[i];
    }

    for (int i = 0; i < np; i++)
    {
        lowest = 9999;
        for (int j = 0; j < nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0 && lowest > temp)
                {
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
    }

    cout << "\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment" << endl;
    for (int i = 0; i < np; i++)
    {
        cout << i + 1 << "\t\t" << p[i] << "\t\t" << parray[i] + 1 << "\t\t" << b[parray[i]] << "\t\t" << fragment[i] << endl;
    }

    return 0;
}
