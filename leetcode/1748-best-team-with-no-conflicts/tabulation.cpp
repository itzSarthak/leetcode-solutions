class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        int n = scores.size();
        vector<pair<int,int>> players;
        vector<vector<int>>dp(n + 1,vector<int>(n + 1,0));

        for(int i = 0; i < n; i++)
            players.push_back({ages[i], scores[i]});

        sort(players.begin(), players.end());


        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
            {
                //  notPick
                int l1 = dp[idx + 1][prev_idx + 1];

                // Pick
                int l2 =-1e9;
                if(prev_idx == -1 || (players[idx].second >= players[prev_idx].second))
                    l2 = players[idx].second + dp[idx + 1][idx + 1];

                dp[idx][prev_idx + 1] = max(l1,l2);
            }
        }

        // return solve(0, -1, players,dp);
        return dp[0][0];
    }
};