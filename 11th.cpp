// Aggressive Cows (Spoj / GFG)
// Problem:
// Place cows in stalls such that minimum distance between any two cows is maximized.

// Example:

// makefile
// Copy
// Edit
// Input: stalls = [1, 2, 4, 8, 9], cows = 3  
// Output: 3

bool canPlace(vector<int>& stalls, int cows, int dist) {
    int count = 1, lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
    }
    return count >= cows;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls.front(), ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlace(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
