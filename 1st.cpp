//  1. Find First and Last Position of Element in Sorted Array
// Problem:
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// Example:

// makefile
// Copy
// Edit
// Input: nums = [5,7,7,8,8,10], target = 8  
// Output: [3,4]

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, bool findFirst) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            if (findFirst) high = mid - 1;
            else low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = binarySearch(nums, target, true);
    int last = binarySearch(nums, target, false);
    return {first, last};
}
