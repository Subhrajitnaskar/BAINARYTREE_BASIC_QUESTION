// Search in a 2D Matrix
// Problem:
// Matrix with sorted rows and sorted first elements of each row. Find if a target exists.
//Example:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3  
// Output: true

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m * n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int val = matrix[mid / n][mid % n];

        if (val == target) return true;
        else if (val < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
