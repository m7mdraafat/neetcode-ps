class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // treat index n as a bar of height 0 to flush the stack
            int curHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] >= curHeight) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }
};