#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> pos;
vector<vector<int>> dp;

bool solve(int idx,int jump,vector<int>& stones){
    int n=stones.size();

    if(idx==n-1)return true;

    if(dp[idx][jump]!=-1)return dp[idx][jump];

    for(int nj=jump-1;nj<=jump+1;nj++){
        if(nj<=0)continue;

        int target=stones[idx]+nj;

        if(pos.count(target)){
            int nextIdx=pos[target];

            if(solve(nextIdx,nj,stones))
                return dp[idx][jump]=1;
        }
    }

    return dp[idx][jump]=0;
}

bool canCross(vector<int>& stones){
    int n=stones.size();

    if(n<2)return true;
    if(stones[1]!=1)return false;

    pos.clear();

    for(int i=0;i<n;i++){
        pos[stones[i]]=i;
    }

    dp.assign(n,vector<int>(n+1,-1));

    return solve(1,1,stones);
}

int main(){
    int n;
    cin>>n;

    vector<int> stones(n);

    for(int i=0;i<n;i++){
        cin>>stones[i];
    }

    cout<<(canCross(stones)?"true":"false")<<"\n";

    return 0;
}