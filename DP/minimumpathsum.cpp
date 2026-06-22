#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int up=solve(grid, dp,i-1,j);
        int left=solve(grid,dp,i,j-1);

        if(i==0) return dp[i][j]=grid[i][j]+left;
        if(j==0) return dp[i][j]=grid[i][j]+up;
        return dp[i][j]=grid[i][j]+min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else if(i==0) dp[i][j]=dp[i][j-1]+grid[i][j];
                else if(j==0) dp[i][j]=dp[i-1][j]+grid[i][j];
                else dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
              return dp[m-1][n-1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read all integers from stdin to support either:
    // 1) Single test: m n followed by m*n values
    // 2) Multiple tests: t followed by t blocks of (m n grid)
    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);
    if (a.empty()) return 0;

    size_t idx = 0;
    auto safe_parse_single = [&](size_t &pos){
        if (pos + 1 >= a.size()) return false;
        long long m = a[pos];
        long long n = a[pos+1];
        if (m < 0 || n < 0) return false;
        long long expected = 2 + m * n;
        return (a.size() - pos) == (size_t)expected;
    };

    Solution sol;

    if (safe_parse_single(idx)) {
        int m = (int)a[0];
        int n = (int)a[1];
        vector<vector<int>> grid(m, vector<int>(n));
        size_t p = 2;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = (int)a[p++];
        cout << sol.minPathSum(grid) << '\n';
        return 0;
    }

    // Otherwise treat first value as number of testcases
    int t = (int)a[0];
    idx = 1;
    for (int tc = 0; tc < t; ++tc) {
        if (idx + 1 >= a.size()) break;
        int m = (int)a[idx++];
        int n = (int)a[idx++];
        if (m < 0 || n < 0) break;
        if (idx + (size_t)m * n > a.size()) break;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = (int)a[idx++];
        cout << sol.minPathSum(grid) << '\n';
    }

    return 0;
}