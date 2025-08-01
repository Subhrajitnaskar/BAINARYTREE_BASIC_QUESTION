//  8. Find Square Root of a Number (Without using sqrt)
// Problem:
// Given a number x, find the integer part of its square root.

// Example:

// css
// Copy
// Edit
// Input: x = 8  
// Output: 2  // sqrt(8) ≈ 2.828

int mySqrt(int x) {
    int low = 0, high = x, ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
