// 3. Find Peak Element
// Problem:
// A peak element is one that is greater than its neighbors. Find any peak.

// Example:

// makefile
// Copy
// Edit
// Input: nums = [1,2,3,1]  
// Output: 2  

int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
