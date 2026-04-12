class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> res;
        for (int num : nums1) {
            int nextGreater = next_greater.count(num) ? next_greater[num] : -1;
            res.push_back(nextGreater);
        }

        return res;
    }
};