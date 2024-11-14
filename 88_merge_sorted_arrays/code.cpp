#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;  // Last index of nums1's total space
        int i = m - 1;      // Last index of nums1's actual elements
        int j = n - 1;      // Last index of nums2's elements

        // Merge in reverse order
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main() {
    Solution solution;

    int m, n;
    
    // Take input for m
    cout << "Enter the number of elements in nums1 (m): ";
    cin >> m;
    
    // Take input for n
    cout << "Enter the number of elements in nums2 (n): ";
    cin >> n;

    vector<int> nums1(m + n);  // nums1 has m elements followed by n spaces
    vector<int> nums2(n);

    // Input for nums1 elements
    cout << "Enter " << m << " elements for nums1 (sorted): ";
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    // Initialize last n positions to 0 for nums1 (extra space)
    for (int i = m; i < m + n; ++i) {
        nums1[i] = 0;
    }

    // Input for nums2 elements
    cout << "Enter " << n << " elements for nums2 (sorted): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    // Call the merge function
    solution.merge(nums1, m, nums2, n);

    // Print the merged array
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

