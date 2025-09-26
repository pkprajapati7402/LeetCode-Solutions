#include <iostream>
#include <algorithm>
using namespace std;

int findMinPlatforms(int arrival[], int departure[], int n) {
    // Sort arrival and departure times
    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int platformsNeeded = 1; // Current platforms needed
    int result = 1;          // Final answer (max platforms needed)
    int i = 1, j = 0;

    while (i < n && j < n) {
        // If next train arrives before previous one departs → need a new platform
        if (arrival[i] <= departure[j]) {
            platformsNeeded++;
            i++;
        }
        // Else → one train has departed, free a platform
        else {
            platformsNeeded--;
            j++;
        }

        // Update result if needed
        result = max(result, platformsNeeded);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    int arrival[n], departure[n];

    cout << "Enter arrival times of trains:\n";
    for (int i = 0; i < n; i++) {
        cin >> arrival[i];
    }

    cout << "Enter departure times of trains:\n";
    for (int i = 0; i < n; i++) {
        cin >> departure[i];
    }

    int ans = findMinPlatforms(arrival, departure, n);
    cout << "\nMinimum Number of Platforms Required = " << ans << endl;

    return 0;
}
