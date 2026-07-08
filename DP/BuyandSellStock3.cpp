#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------------------- Memoization --------------------
    int solve(vector<vector<vector<int>>> &dp, int i, vector<int> &prices, int buy, int flag) {
        if (flag == 0) return 0;
        if (i == prices.size()) return 0;

        if (dp[i][buy][flag] != -1)
            return dp[i][buy][flag];

        int profit = 0;

        if (buy) {
            profit = max(
                -prices[i] + solve(dp, i + 1, prices, 0, flag),
                solve(dp, i + 1, prices, 1, flag)
            );
        }
        else {
            profit = max(
                prices[i] + solve(dp, i + 1, prices, 1, flag - 1),
                solve(dp, i + 1, prices, 0, flag)
            );
        }

        return dp[i][buy][flag] = profit;
    }

    // -------------------- Tabulation --------------------
    int tabulation(vector<int> &prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, 0))
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int flag = 1; flag <= 2; flag++) {

                    if (buy) {
                        dp[i][buy][flag] = max(
                            -prices[i] + dp[i + 1][0][flag],
                            dp[i + 1][1][flag]
                        );
                    }
                    else {
                        dp[i][buy][flag] = max(
                            prices[i] + dp[i + 1][1][flag - 1],
                            dp[i + 1][0][flag]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }

    // -------------------- Space Optimization --------------------
    int spaceOptimization(vector<int> &prices) {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int flag = 1; flag <= 2; flag++) {

                    if (buy) {
                        curr[buy][flag] = max(
                            -prices[i] + ahead[0][flag],
                            ahead[1][flag]
                        );
                    }
                    else {
                        curr[buy][flag] = max(
                            prices[i] + ahead[1][flag - 1],
                            ahead[0][flag]
                        );
                    }
                }
            }

            ahead = curr;
        }

        return ahead[1][2];
    }

    int maxProfit(vector<int>& prices) {

        // Memoization
        // vector<vector<vector<int>>> dp(
        //     prices.size(),
        //     vector<vector<int>>(2, vector<int>(3, -1))
        // );
        // return solve(dp, 0, prices, 1, 2);

        // Tabulation
        return tabulation(prices);

        // Space Optimization
        // return spaceOptimization(prices);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution obj;
    cout << obj.maxProfit(prices) << endl;

    return 0;
}