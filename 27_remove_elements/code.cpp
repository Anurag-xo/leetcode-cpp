#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < nums.size(); readIndex++) {
            if (nums[readIndex] != val) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        return writeIndex;
    }
};

int main() {
    int n, val;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::cout << "Enter the value to remove: ";
    std::cin >> val;

    Solution solution;
    int newSize = solution.removeElement(nums, val);

    std::cout << "The new size of the array is: " << newSize << std::endl;
    std::cout << "The modified array is: ";
    for (int i = 0; i < newSize; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
