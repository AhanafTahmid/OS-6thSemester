#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main()
{
    int n; // Number of frames
    cout << "Enter the number of frames: ";
    cin >> n;

    int m; // Number of pages
    cout << "Enter the number of pages: ";
    cin >> m;

    queue<int> fifoQueue; //page replacement queue
    unordered_set<int> pageSet; //track of pages in memory
    int pageFaults = 0;

    cout << "Enter the page reference string:\n";
    for (int i = 0; i < m; i++)
    {
        int page;
        cin >> page;

        // Check  page is not present in memory
        if (pageSet.find(page) == pageSet.end())
        {
            pageFaults++;

            // queue is full,page replacement
            if (fifoQueue.size() == n)
            {
                int victimPage = fifoQueue.front();
                fifoQueue.pop();
                pageSet.erase(victimPage);
            }

            fifoQueue.push(page);
            pageSet.insert(page);
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
