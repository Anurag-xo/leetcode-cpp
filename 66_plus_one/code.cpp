#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
   int n;
   std::cout << "Enter the number of digits: ";
   std::cin >> n;

   std::vector<int> digits(n);
   std::cout << "Enter the digits:\n";
   for (int i = 0; i < n; i++) {
       std::cin >> digits[i];
   }

   Solution solution;
   std::vector<int> result = solution.plusOne(digits);

   std::cout << "Result after adding one: ";
   for (int digit : result) {
       std::cout << digit;
   }
   std::cout << std::endl;

   return 0;
}
