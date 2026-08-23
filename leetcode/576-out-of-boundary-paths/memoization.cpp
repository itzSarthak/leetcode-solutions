class Solution {
public:
    int solve(int i,int j,int maxMove,int m,int n,vector<vector<vector<long long>>>& dp)
    {
        // base case 
        if((i > m || i < 0) || (j > n || j < 0)) return 1;
        else if(maxMove == 0) return 0;

        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];

        // otherwise
        long long w,x,y,z = 0;

        w = solve(i + 1,j,maxMove - 1,m,n,dp);

        x = solve(i,j + 1,maxMove - 1,m,n,dp);

        y = solve(i - 1,j,maxMove - 1,m,n,dp);

        z = solve(i,j - 1,maxMove - 1,m,n,dp);


        return dp[i][j][maxMove] = (w + x + y + z)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n, vector<long long>(maxMove + 1, -1)));
        return solve(startRow,startColumn,maxMove,m - 1,n - 1,dp);
    }
};