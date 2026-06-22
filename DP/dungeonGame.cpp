#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i,int j, vector<vector<int>> & dungeon,int m ,int n){
        if(i==m-1 && j==n-1){
            return dungeon[i][j]>=0? 1: abs(dungeon[i][j])+1;
        }

        if(i>=m || j>=n) return 1e9;

        if(dp[i][j]!=1e9) return dp[i][j];

        int right=solve(i,j+1,dungeon,m,n);
        int down=solve(i+1,j,dungeon,m,n);

        int next=abs(min(1,dungeon[i][j]-min(right,down)));

        return dp[i][j]=next?next:1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        dp.assign(m+1,vector<int>(n+1,1e9));

        // int ans=solve(0,0,dungeon,m,n);
        // return ans?ans:1;

        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {

                int nextHealth = min(dp[i + 1][j], dp[i][j + 1]);

                int required = nextHealth - dungeon[i][j];

                dp[i][j] = max(1, required);
            }
        }

        return dp[0][0];
    }
};

int main() {

    vector<vector<int>> dungeon = {
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };

    Solution obj;

    int ans = obj.calculateMinimumHP(dungeon);

    cout << "Minimum HP required: " << ans << endl;

    return 0;
}