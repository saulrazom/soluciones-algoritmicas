#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squares(n);
        int left = 0;
        int right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int left_abs = abs(nums[left]);
            int right_abs = abs(nums[right]);

            if (left_abs > right_abs) {
                squares[index--] = left_abs * left_abs;
                ++left;
            } else {
                squares[index--] = right_abs * right_abs;
                --right;
            }
        }

        return squares;
    }
};