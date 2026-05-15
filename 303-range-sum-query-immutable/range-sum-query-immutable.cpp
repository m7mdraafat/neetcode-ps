class NumArray {
private:
    vector<int> prefix;
    int sumSoFar = 0;
public:
    NumArray(vector<int>& nums) {
        for (int num : nums) {
            sumSoFar += num;
            prefix.push_back(sumSoFar);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix[right];
        }
        return prefix[right] - prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */