class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int,int>>v(nums.size(),{0,0});
        for(int i = 0; i < nums.size(); i++)
        {
            v[i].first = nums[i];
            v[i].second = i;
        }
        sort(v.begin(),v.end());
        
        vector<int>res;
        int i = 0,j = nums.size() - 1;
        while(i < j)
        {
            if(v[i].first + v[j].first == target)
            {
                res.push_back(v[i].second);
                res.push_back(v[j].second);
                break;
            }
            else if(v[i].first + v[j].first > target)
                j--;
            else
                i++;
        }
        return res;
    }
};