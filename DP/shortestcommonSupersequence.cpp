#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string form(int i, int j, string str1, string str2,
                vector<vector<int>> &dp) {

        if (i == 0 && j == 0) return "";

        if (i == 0) return str2.substr(0, j);

        if (j == 0) return str1.substr(0, i);

        if (str1[i - 1] == str2[j - 1]) {
            string ans = form(i - 1, j - 1, str1, str2, dp);
            ans.push_back(str1[i - 1]);
            return ans;
        }
        else {
            if (dp[i][j - 1] >= dp[i - 1][j]) {
                string ans = form(i, j - 1, str1, str2, dp);
                ans.push_back(str2[j - 1]);
                return ans;
            }
            else {
                string ans = form(i - 1, j, str1, str2, dp);
                ans.push_back(str1[i - 1]);
                return ans;
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // LCS table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return form(n, m, str1, str2, dp);
    }
};

int main() {
    Solution obj;

    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    string result = obj.shortestCommonSupersequence(str1, str2);

    cout << "Shortest Common Supersequence: " << result << endl;

    return 0;
}