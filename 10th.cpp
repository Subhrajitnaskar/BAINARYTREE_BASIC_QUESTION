//  Book Allocation Problem (GFG/CodeStudio)
// Problem:
// Allocate books to m students such that the maximum pages assigned to a student is minimized.

// Example:

// makefile
// Copy
// Edit
// Input: pages = [12, 34, 67, 90], m = 2  
// Output: 113

bool isPossible(vector<int>& pages, int m, int maxPages) {
    int student = 1, sum = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (pages[i] > maxPages) return false;
        if (sum + pages[i] > maxPages) {
            student++;
            sum = pages[i];
        } else {
            sum += pages[i];
        }
    }
    return student <= m;
}

int allocateBooks(vector<int>& pages, int m) {
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int res = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(pages, m, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}
