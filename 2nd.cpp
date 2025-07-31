//  Search in Rotated Sorted Array
// Problem:
// You are given a rotated sorted array. Find the index of the target element.

// Example:

// makefile
// Copy
// Edit
// Input: nums = [4,5,6,7,0,1,2], target = 0  
// Output: 4

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) return mid;

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
