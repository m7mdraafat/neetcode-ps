class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        /* brute force iterate over array for each range [i, j] where j = i + 1
            find the minimum for each range.
        */

        int n = arr.size();
        stack<int> st;
        long long sum = 0;
        for (int i = 0; i <= n; i++) {
            int curVal = (i == n) ? 0 : arr[i];
            while (!st.empty() && arr[st.top()] >= curVal) {
                int mid = st.top();
                st.pop();
                int leftBound = st.empty() ? -1 : st.top();
                int rightBound = i;

                int leftCount = mid - leftBound; // choices for subarray start
                int rightCount = rightBound - mid; // choices for subarray end

                sum = (sum + (long long)arr[mid] % MOD * leftCount % MOD * rightCount) % MOD;
            }

            st.push(i);
        }

        return sum;
    }
};