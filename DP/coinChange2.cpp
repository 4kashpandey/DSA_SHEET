#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int amount,vector<int> & coins, vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i==0)return amount%coins[i]==0;

        if(dp[i][amount]!=-1)return dp[i][amount];

        int notp=solve(i-1,amount,coins,dp);

        int pick=0;
        if(amount>=coins[i]){
            pick=solve(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=notp+pick;

    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        // Memoization
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return solve(n-1,amount,coins,dp);


        // Space Optimization
        vector<long long> prev(amount+1,0);

        // Base case
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0)
                prev[i]=1;
        }

        prev[0]=1;

        for(int i=1;i<n;i++){

            // Forward traversal
            for(int j=coins[i];j<=amount;j++){

                long long notPick = prev[j];

                long long pick = prev[j-coins[i]];

                prev[j] = notPick + pick;
            }
        }

        return prev[amount];
    }
};

int main(){

    int n;
    cin >> n;

    vector<int> coins(n);

    for(int i=0;i<n;i++){
        cin >> coins[i];
    }

    int amount;
    cin >> amount;

    Solution obj;

    cout << obj.change(amount,coins);

    return 0;
}