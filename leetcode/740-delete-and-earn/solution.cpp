class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++)
            maxi = max(maxi, nums[i]);

        vector<int> points(maxi + 1, 0);
        for(int i = 0; i < nums.size(); i++)
            points[nums[i]] += nums[i];

        vector<int> dp(maxi + 1, 0);
        dp[0] = 0;

        if(maxi >= 1)
            dp[1] = points[1];

        for(int i = 2; i <= maxi; i++)
        {
            int notTake = dp[i - 1];
            int take = points[i] + dp[i - 2];

            dp[i] = max(take, notTake);
        }

        return dp[maxi];
    }
};
