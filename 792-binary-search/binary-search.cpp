class Solution {
public:
    int search(vector<int>& nums, int target) {
        // array is sorted? yes, find specific element? -> yes
        // each iteration answer with "yes" or "no"? -> yes -> binary seatch
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};