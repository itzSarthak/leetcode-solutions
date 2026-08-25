class Solution {
public:
    double knightProbability(int n, int k, int row, int col)
    {
        int maxk = k;
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(maxk + 1,0)));

        // base case 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                dp[i][j][0] = 1;
        }


        for(int k = 1; k <= maxk; k++)
        {
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    double ans = 0;

                    for(int di = -2; di <= 2; di++)
                    {
                        for(int dj = -2; dj <= 2; dj++)
                        {
                            if(abs(di) == abs(dj) || di == 0 || dj == 0) continue;
                            if(r + di < 0 || r + di >= n || c + dj < 0 || c + dj >= n) continue;

                            ans += 0.125 * dp[r + di][c + dj][k - 1];
                        }
                    }

                    dp[r][c][k] = ans;
                }
            }
        }
        return dp[row][col][maxk];
    }
};