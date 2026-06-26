#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =========================
    // 1. MEMOIZATION
    // =========================

    int solveMemo(int idx, int W,
                   vector<int>& val,
                   vector<int>& wt,
                   vector<vector<int>>& dp) {

        // Base case
        if(idx == 0) {
            if(wt[0] <= W)
                return val[0];

            return 0;
        }

        if(dp[idx][W] != -1)
            return dp[idx][W];

        // Not take
        int notTake =
            solveMemo(idx-1,W,val,wt,dp);

        // Take
        int take = 0;

        if(wt[idx] <= W) {
            take = val[idx] +
                    solveMemo(
                    idx-1,
                    W-wt[idx],
                    val,
                    wt,
                    dp);
        }

        return dp[idx][W] =
               max(take,notTake);
    }

    int knapsackMemo(
                    int W,
                    vector<int>& val,
                    vector<int>& wt,
                    int n) {

        vector<vector<int>>
        dp(n,vector<int>(W+1,-1));

        return solveMemo(
                        n-1,
                        W,
                        val,
                        wt,
                        dp);
    }



    // =========================
    // 2. TABULATION
    // =========================

    int knapsackTabu(
                    int W,
                    vector<int>& val,
                    vector<int>& wt,
                    int n) {

        vector<vector<int>>
        dp(n,vector<int>(W+1,0));

        // Base case
        for(int w=wt[0];w<=W;w++)
            dp[0][w]=val[0];

        for(int i=1;i<n;i++) {

            for(int w=0;w<=W;w++) {

                int notTake=
                dp[i-1][w];

                int take=0;

                if(wt[i]<=w)
                    take=
                    val[i]+
                    dp[i-1][w-wt[i]];

                dp[i][w]=
                max(take,notTake);
            }
        }

        return dp[n-1][W];
    }



    // =========================
    // 3. SPACE OPTIMIZATION
    // =========================

    int knapsackSO(
                    int W,
                    vector<int>& val,
                    vector<int>& wt,
                    int n) {

        vector<int> prev(W+1,0);

        // Base case
        for(int w=wt[0];w<=W;w++)
            prev[w]=val[0];

        for(int i=1;i<n;i++) {

            // Traverse backwards
            for(int w=W;w>=0;w--) {

                int notTake=
                prev[w];

                int take=0;

                if(wt[i]<=w)
                    take=
                    val[i]+
                    prev[w-wt[i]];

                prev[w]=
                max(take,notTake);
            }
        }

        return prev[W];
    }
};



int main() {

    int n;
    cin>>n;

    vector<int> val(n),wt(n);

    // values
    for(int i=0;i<n;i++)
        cin>>val[i];

    // weights
    for(int i=0;i<n;i++)
        cin>>wt[i];

    int W;
    cin>>W;

    Solution obj;

    cout<<"Memoization: "
        <<obj.knapsackMemo(
        W,val,wt,n)
        <<endl;

    cout<<"Tabulation: "
        <<obj.knapsackTabu(
        W,val,wt,n)
        <<endl;

    cout<<"Space Optimized: "
        <<obj.knapsackSO(
        W,val,wt,n)
        <<endl;

    return 0;
}