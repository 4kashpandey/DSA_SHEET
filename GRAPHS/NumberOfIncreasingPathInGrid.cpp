class Solution {
public:
    int mod=1000000007;
    int solve(vector<vector<int>> & matrix, vector<vector<int>> &dp , int i, int j){
        if(i<0 || i>=matrix.size())return 0;
        if( j<0 || j>=matrix[0].size() )return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int count=1;
        for( int d=0 ;d<4;d++){
            int ni=dx[d]+i;
            int nj=dy[d]+j;

            if(ni>=0 && ni<matrix.size() && nj>=0  && nj<matrix[0].size() && matrix[ni][nj]> matrix[i][j]){
                count=(count+solve(matrix,dp,ni,nj))%mod;
                
            }
        }
        dp[i][j]=count;
        return count;
    }
    int countPaths(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum=(sum+solve(matrix,dp,i,j))%mod;
            }
        }
        return sum;
    }
};