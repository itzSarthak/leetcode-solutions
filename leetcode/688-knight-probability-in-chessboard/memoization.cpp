class Solution {
public:
    double solve(int n, int k, int row, int col,vector<vector<vector<double>>>& dp)
    {
        // base case
        if((row >= n || row < 0) || (col >= n || col < 0)) return 0;
        if(k == 0) return 1;


        if(dp[row][col][k]  != -1) return dp[row][col][k];

        // every position we have eight possibility 
        double ans = 0;
        for(int di = -2; di <= 2; di++)
        {
            for(int dj = -2; dj <= 2; dj++)
            {
                if(abs(di) == abs(dj) || di == 0 || dj == 0) continue;
                ans = ans + (0.125) * solve(n,k - 1,row + di,col + dj,dp);
            }
        }

        // double a = (0.125)

        return dp[row][col][k] = ans;
    }
    double knightProbability(int n, int k, int row, int col)
    {
        // row - [0,n-1]
        // col - same
        // k - [k,0]
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k + 1,-1)));
        return solve(n,k,row,col,dp);
    }
};