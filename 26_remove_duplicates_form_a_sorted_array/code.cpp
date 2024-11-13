#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
	int res;
	cout << "Enter the number of elements in the array: ";
	cin >> res;

	vector<int> nums(res);
	cout << "Enter the array elements:\n";
	for(int i = 0; i < res; i++) {
		cin >> nums[i];
	}

	Solution solution;
	int newsize = solution.removeDuplicates(nums);
	cout << "The new size of the array is: " << newsize << endl;
	return 0;
}

