class Solution {
public:

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>>dp(n + 1,vector<int>(m + 1,0));

        for(int idx1 = 1; idx1 <= n; idx1++)
        {
            for(int idx2 = 1; idx2 <= m; idx2++)
            {
                if(nums1[idx1 - 1] == nums2[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];

                 else
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2],dp[idx1][idx2 - 1]);
            }
        }
        return dp[n][m];
    }
};