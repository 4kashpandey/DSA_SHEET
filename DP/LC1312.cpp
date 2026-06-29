//minimum insertions to make string palindrome 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lcs_length(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    int minInsertions(string s) {
        int n = s.size();

        string y = s;
        reverse(y.begin(), y.end());

        int x = n - lcs_length(s, y);

        return x;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = obj.minInsertions(s);

    cout << "Minimum insertions required: " << result << endl;

    return 0;
}