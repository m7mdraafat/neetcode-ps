class Solution {
private:
    int totalZeros = 0;
    int totalOnes = 0;
    unordered_map<int, vector<int>> balancedPositions;

    int maxWindowLen(int imbalance) {
        if (imbalance == 0) return INT_MAX;
        if (imbalance == 2) return 2 * totalZeros;
        if (imbalance == -2) return 2 * totalOnes;
        return 0;
    }

    void tryUpdate(int balance, int j, int targetBalance, int& maxLen) {
        auto it = balancedPositions.find(targetBalance);
        if (it == balancedPositions.end()) return;

        int imbalance = balance - targetBalance;
        int maxWindow = maxWindowLen(imbalance);
        int minPos = j - maxWindow;

        auto& positions = it->second;
        auto pos = lower_bound(positions.begin(), positions.end(), minPos);
        if (pos != positions.end()) {
            maxLen = max(maxLen, j - *pos);
        }
    }

    void saveBalance(int balance, int j) {
        balancedPositions[balance].push_back(j);
    }

public:
    int longestBalanced(string s) {
        int n = s.size();
        totalZeros = count(s.begin(), s.end(), '0');
        totalOnes = n - totalZeros;

        balancedPositions[0].push_back(0);
        int balance = 0;
        int maxLen = 0;

        for (int j = 1; j <= n; j++) {
            balance += (s[j - 1] == '1') ? 1 : -1;

            tryUpdate(balance, j, balance, maxLen);
            tryUpdate(balance, j, balance - 2, maxLen);
            tryUpdate(balance, j, balance + 2, maxLen);

            saveBalance(balance, j);
        }

        return maxLen;
    }
};