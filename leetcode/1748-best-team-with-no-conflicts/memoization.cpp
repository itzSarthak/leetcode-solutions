class Solution {
public:
    int solve(int idx,int prev_idx,vector<pair<int,int>>& players,vector<vector<int>>& dp)
    {
        // base case
        if(idx == players.size()) return 0;

        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];

        // notPick
        int l1 = solve(idx + 1,prev_idx,players,dp);

        // Pick
        int l2 =-1e9;
        if(prev_idx == -1 || (players[idx].second >= players[prev_idx].second))
            l2 = players[idx].second + solve(idx + 1,idx,players,dp);

        return dp[idx][prev_idx + 1] = max(l1,l2);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        int n = scores.size();
        vector<pair<int,int>> players;
        vector<vector<int>>dp(n,vector<int>(n + 1,-1));

        for(int i = 0; i < n; i++)
            players.push_back({ages[i], scores[i]});

        sort(players.begin(), players.end());

        return solve(0, -1, players,dp);
    }
};