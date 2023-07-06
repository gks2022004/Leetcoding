#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumDifferenceBetweenPackets(vector<int>& packets, int m) {
    int n = packets.size();
    if (n < m) {
        // Not enough packets to distribute to each student
        return -1;
    }

    // Sort the packets in ascending order
    sort(packets.begin(), packets.end());

    int minDifference = packets[n - 1] - packets[0]; // Initialize with the maximum difference

    // Find the minimum difference between packets
    for (int i = 0; i + m - 1 < n; i++) {
        int difference = packets[i + m - 1] - packets[i];
        if (difference < minDifference) {
            minDifference = difference;
        }
    }

    return minDifference;
}

int main() {
    vector<int> packets = {3, 4, 1, 9, 6, 7, 5};
    int m = 3;

    int minDifference = minimumDifferenceBetweenPackets(packets, m);

    if (minDifference != -1) {
        cout << "Minimum difference between packets: " << minDifference << endl;
    } else {
        cout << "Cannot distribute packets to each student." << endl;
    }

    return 0;
}
