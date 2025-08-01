//  Capacity to Ship Packages Within D Days (Leetcode 1011)
// Problem:
// Given an array weights and D days, find the minimum ship capacity.

// Example:

// makefile
// Copy
// Edit
// Input: weights = [1,2,3,1,1], D = 4  
// Output: 3

bool isValid(vector<int>& weights, int capacity, int days) {
    int total = 0, count = 1;
    for (int w : weights) {
        if (total + w > capacity) {
            count++;
            total = 0;
        }
        total += w;
    }
    return count <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low < high) {
        int mid = (low + high) / 2;
        if (isValid(weights, mid, days))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
