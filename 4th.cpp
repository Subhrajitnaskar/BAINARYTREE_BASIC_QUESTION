//  Koko Eating Bananas (Leetcode 875)
// Problem:
// Given piles of bananas and hours h, find the minimum eating speed (k) so Koko can eat all bananas in h hours.
// Example:

// makefile
// Copy
// Edit
// Input: piles = [3,6,7,11], h = 8  
// Output: 4

int totalHours(vector<int>& piles, int k) {
    int hours = 0;
    for (int pile : piles) {
        hours += (pile + k - 1) / k;
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (totalHours(piles, mid) <= h)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
