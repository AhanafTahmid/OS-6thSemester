#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    int n; // Number of frames
    std::cout << "Enter the number of frames: ";
    std::cin >> n;

    int m; // Number of pages
    std::cout << "Enter the number of pages: ";
    std::cin >> m;

    std::unordered_set<int> pageSet; // Set to keep track of pages in memory
    std::vector<int> pageOrder; // Vector to store page order
    int pageFaults = 0;

    std::cout << "Enter the page reference string:\n";
    for (int i = 0; i < m; ++i) {
        int page;
        std::cin >> page;

        // Check if the page is not present in memory
        if (pageSet.find(page) == pageSet.end()) {
            ++pageFaults;

            // If the set is full, perform page replacement
            if (pageSet.size() == n) {
                int farthestFuture = -1;
                int victimPage = -1;

                for (const auto &p : pageSet) {
                    auto futurePos = std::find(pageOrder.begin() + i, pageOrder.end(), p);
                    if (futurePos == pageOrder.end()) {
                        victimPage = p;
                        break;
                    }

                    if (farthestFuture < std::distance(pageOrder.begin() + i, futurePos)) {
                        farthestFuture = std::distance(pageOrder.begin() + i, futurePos);
                        victimPage = p;
                    }
                }

                pageSet.erase(victimPage);
            }

            pageSet.insert(page);
        }

        pageOrder.push_back(page);
    }

    std::cout << "Total Page Faults: " << pageFaults << std::endl;

    return 0;
}
