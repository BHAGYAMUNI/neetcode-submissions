class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);
            if (nums[index] < 0) {
                // If already negative, it's a duplicate
                return index;
            }
            nums[index] = -nums[index];
        }
        return -1; // Should never reach here if there's always a duplicate
    }
};
