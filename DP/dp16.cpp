#include<bits/stdc++.h>
using namespace std;

bool func(int idx,int target,vector<int>& test,
          vector<vector<int>>& dp){

    if(target==0)return true;

    if(idx==0)return test[0]==target;

    if(dp[idx][target]!=-1)
        return dp[idx][target];

    bool notTaken=func(idx-1,target,test,dp);

    bool taken=false;

    if(test[idx]<=target){
        taken=func(idx-1,
                   target-test[idx],
                   test,
                   dp);
    }

    return dp[idx][target]=notTaken||taken;
}

int solve(vector<int>& test){

    int n=test.size();

    int total=0;

    for(int x:test)total+=x;

    vector<vector<int>> dp(n,
    vector<int>(total+1,0));

    /*
    ----------MEMOIZATION----------
    
    vector<vector<int>> dp(n,
    vector<int>(total+1,-1));

    for(int i=0;i<=total;i++){
        func(n-1,i,test,dp);
    }
    */

    
    //----------TABULATION----------

    for(int i=0;i<n;i++)
        dp[i][0]=true;

    if(test[0]<=total)
        dp[0][test[0]]=true;

    for(int idx=1;idx<n;idx++){

        for(int target=1;target<=total;target++){

            bool notTaken=
            dp[idx-1][target];

            bool taken=false;

            if(test[idx]<=target){
                taken=
                dp[idx-1]
                  [target-test[idx]];
            }

            dp[idx][target]=
            taken||notTaken;
        }
    }

    int ans=INT_MAX;

    for(int sum1=0;sum1<=total/2;sum1++){

        if(dp[n-1][sum1]){

            int sum2=total-sum1;

            ans=min(ans,
            abs(sum1-sum2));
        }
    }

    return ans;
}


/*
--------SPACE OPTIMIZATION--------

int solve(vector<int>& test){

    int n=test.size();

    int total=0;

    for(int x:test)total+=x;

    vector<int> prev(total+1,0);

    prev[0]=true;

    if(test[0]<=total)
        prev[test[0]]=true;

    for(int idx=1;idx<n;idx++){

        vector<int> curr(total+1,0);

        curr[0]=true;

        for(int target=1;
            target<=total;
            target++){

            bool notTaken=
            prev[target];

            bool taken=false;

            if(test[idx]<=target){
                taken=
                prev[target-test[idx]];
            }

            curr[target]=
            taken||notTaken;
        }

        prev=curr;
    }

    int ans=INT_MAX;

    for(int sum1=0;
        sum1<=total/2;
        sum1++){

        if(prev[sum1]){

            int sum2=
            total-sum1;

            ans=min(ans,
            abs(sum1-sum2));
        }
    }

    return ans;
}
*/

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int> test(n);

        for(int i=0;i<n;i++)
            cin>>test[i];

        cout<<solve(test)<<endl;
    }

    return 0;
}