#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    unsigned long long solve(int i, int j, string &s, string &t,
                             vector<vector<unsigned long long>> &dp) {
        
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) {
            return dp[i][j] = solve(i-1, j-1, s, t, dp) +
                              solve(i-1, j, s, t, dp);
        }
        else {
            return dp[i][j] = solve(i-1, j, s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long>> dp(
            n + 1, vector<unsigned long long>(m + 1, -1)
        );

        // Memoization:
        // return solve(n, m, s, t, dp);

        // Space Optimization:
        vector<unsigned long long> prev(m + 1, 0);
        prev[0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= 1; j--) {
                if(s[i-1] == t[j-1]) {
                    prev[j] = prev[j-1] + prev[j];
                }
            }
        }

        return (int)prev[m];
    }
};

int main() {
    Solution obj;

    string s, t;

    cout << "Enter source string: ";
    cin >> s;

    cout << "Enter target string: ";
    cin >> t;

    cout << "Number of distinct subsequences: "
         << obj.numDistinct(s, t) << endl;

    return 0;
}