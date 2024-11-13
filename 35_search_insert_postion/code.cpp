#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right -left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    int n, target;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::cout << "Enter the target value: ";
    std::cin >> target;

    Solution solution;
    int insertIndex = solution.searchInsert(nums, target);

    std::cout << "The index where the target value should be inserted is: " << insertIndex << std::endl;

    return 0;
};

