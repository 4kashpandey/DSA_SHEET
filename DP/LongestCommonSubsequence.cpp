#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int i,int j, string text1 ,string text2,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        if(text1[i]==text2[j])
            return dp[i][j]=1+solve(i-1,j-1,text1,text2,dp);

        return dp[i][j]=max(
            solve(i-1,j,text1,text2,dp),
            solve(i,j-1,text1,text2,dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        // Technique 1 + 2 : Recursion + Memoization
        // Uncomment below to use Memoization

        /*
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
        */


        // Technique 3 : Tabulation using shifting of indices
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n+1;i++)
            dp[i][0]=0;

        for(int j=0;j<m+1;j++)
            dp[0][j]=0;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
         int i = n, j = m;
        string lcs = "";

        // Traverse dp table from bottom-right to top-left
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                // Characters match, add to result and move diagonally
                lcs += text1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // Move up if top cell has greater value
                i--;
            } else {
                // Move left otherwise
                j--;
            }
        }

        cout<< "Longest Common Subsequence: ";
        reverse(lcs.begin(), lcs.end());
        cout << lcs << endl;

        return dp[n][m];
    }
};

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    Solution obj;

    int ans = obj.longestCommonSubsequence(text1, text2);

    cout << "Length of Longest Common Subsequence: "
         << ans << endl;

    return 0;
}