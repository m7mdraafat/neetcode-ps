class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // given temperatures -> return array of distance between each day and its next warmer day -> if there is no keep it 0
        /* iterate over each element in the array and try to find the next warmer day on the right side. and calculate the disatance
        O(n^2) time, and O(1) space
        */         

        /* bottleneck is the inner loop, we need to answer the question of what is the next warmer day for current day?
        so we solve it using Monotonic stack technique
        monotonic stack technique is: a way to maintain a stack in sorted order (incresing or decreasing).
        when a new element (next days) violates the order, pop until it doesn't.
        each pop answers the question for the popped element.
        the new element that triggered the pop IS the answer O(1) time.
        */

        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // the index of the day itself not the value to avoid duplicates

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};