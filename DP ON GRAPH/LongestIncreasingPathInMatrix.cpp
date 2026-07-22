class Solution {
public:
    int solve(vector<vector<int>> & matrix, vector<vector<int>> &dp , int i, int j){
        if(i<0 || i>=matrix.size())return 0;
        if( j<0 || j>=matrix[0].size() )return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};

        int lis=1;

        for( int d=0 ;d<4;d++){
            int ni=dx[d]+i;
            int nj=dy[d]+j;

            if(ni>=0 && ni<matrix.size() && nj>=0  && nj<matrix[0].size() && matrix[ni][nj]> matrix[i][j]){
                lis=max(lis,solve(matrix,dp,ni,nj)+1);
            }
        }
        return dp[i][j]=lis;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        int maxi=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(solve(matrix,dp,i,j),maxi);
            }
        }
        return maxi;
    }
};