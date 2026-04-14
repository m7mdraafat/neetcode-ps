class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        if (target > nums[r - 1]) {
            return r;
        }

        int ans = -1;
        while (l < r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] >= target) {
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};