class Solution {
public:
    int f(int j, int i, vector<vector<int>>& memo, const vector<vector<int>>& triangle, int n) {
        if (j == n) return 0;
        if (memo[j][i] != INT_MAX) return memo[j][i];
        int best = triangle[j][i] + min(f(j + 1, i, memo, triangle, n),f(j + 1, i + 1, memo,triangle, n));
        return memo[j][i] = best;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        return f(0, 0, memo, triangle, n);
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));   // row n = base case, all 0
        for (int j = n - 1; j >= 0; j--)          // f(j, ...) reads row j+1 → fill bottom-up
            for (int i = 0; i <= j; i++)          // row j has j+1 elements
                dp[j][i] = triangle[j][i] + min(dp[j + 1][i], dp[j + 1][i + 1]);
        return dp[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<int> dp(n + 1, 0);                 // holds "the row below"
        for (int j = n - 1; j >= 0; j--)
            for (int i = 0; i <= j; i++)          // forward: dp[i+1] is still the old row
                dp[i] = triangle[j][i] + min(dp[i], dp[i + 1]);
        return dp[0];
    }
};
