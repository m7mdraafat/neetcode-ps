class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Duplicates? No menotioned as special, treat normally
        // Array Size? -> Up to 10^4, so O(n^2) might be tight, O(n) preferred

        // Brute force:
        // The naive approach: for each element, walk forward (warpping around) up to n - 1 steps looking for something greater.
        /*  for each i:
                for each j = 1 to n - 1:
                    if (nums[(i+j) % n] > nums[i]:
                        result[i] = nums[(i + j) % n]
                        break;
        Time: O(n^2), space O(1)
        */

        // The bottleneck is the inner scan - for each element we're searching for the next greater. That's exactly what a monotonic stack solves in amortized O(1) per element.

        // Simulate the circular array by iterating twice through the array (indices 0 to 2n - 1) using i % n to wra. 
        // result: [-1, -1, -1], stack=[]
        // [1, 2, 1]
        /*
            i=0 val=1 stack empty, push 0 -> stack=[0]
            i=1 val=2 nums[0]=1 -> pop 0, result[0]=2, push 1 -> stack=[1]
            i=2 val=1 1 < 2, push 2 -> stack=[1, 2]
            ------
            second pass (wrap-around)
            i=3 idx=0, val=1: 1 < 2 no pops -> DON'T Push (already processed)
            i=4 idx=1 val=2: 2 >= nums[2]=1 -> pop 2 result[2]=2
                             2 == nums[1]=2 -> not greater, stop
            Result: [2, -1, 2]
        */

        int n = nums.size();
        stack<int> stk;
        vector<int> result(n, -1);

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while(!stk.empty() && nums[stk.top()] < nums[idx]) {
                result[stk.top()] = nums[idx];
                stk.pop();
            }
            // only push on first pass - second pass is just for answering
            if (i < n) {
                stk.push(idx);
            }
        }

        return result;
    }
};