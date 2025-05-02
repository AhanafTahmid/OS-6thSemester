/*1 0 1 2 5 0 2 4 5 0 7 3  2 1 0 5  4 8 9 1 0 2 5 8 0 1 2 0*/
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n; // Number of frames
    cout << "Enter the number of frames: ";
    cin >> n;

    int m; // Number of pages
    cout << "Enter the number of pages: ";
    cin >> m;

    list<int> lruList; // LRU page replacement list
    int pageFaults = 0;

    cout << "Enter the page reference string:\n";
    for (int i = 0; i < m; i++)
    {
        int page;
        cin >> page;
        bool pageFound = false;

        for (auto it = lruList.begin(); it != lruList.end(); ++it)
        {
            if (*it == page)
            {
                // Page is already in memory, move it to the front of the list
                lruList.erase(it);
                lruList.push_front(page);
                pageFound = true;
                break;
            }
        }

        if (!pageFound)
        {
            pageFaults++;

            if (lruList.size() == n)
            {
                lruList.pop_back(); // Remove the least recently used page
            }

            lruList.push_front(page); // Add the new page to the front of the list
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
