//  6. Find Minimum in Rotated Sorted Array
// Problem:
// Given a rotated sorted array with no duplicates, find the minimum element.

// Example:

// makefile
// Copy
// Edit
// Input: nums = [3,4,5,1,2]  
// Output: 1

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return nums[low];
}
