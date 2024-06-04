#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = -1;

        // Find the first decreasing element from the end
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                x = i - 1;
                break;
            }
        }

        // If no such element is found, reverse the entire array
        if (x == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the element just larger than nums[x] to swap with
        for (int j = n - 1; j > x; j--) {
            if (nums[j] > nums[x]) {
                swap(nums[x], nums[j]);
                break;
            }
        }

        // Reverse the subarray from x + 1 to the end
        reverse(nums.begin() + x + 1, nums.end());
        
    }
};