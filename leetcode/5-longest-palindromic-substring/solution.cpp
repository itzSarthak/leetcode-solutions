class Solution
{
public:
    int isPal(int l,int r,string &s)
    {
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s)
    {
        int res_len = 0;
        int n = s.size();
        int st_idx = 0;
        int l1,l2,l;
        
        for(int i=0;i<n;i++)
        {
            l1 = isPal(i,i,s);
            l2 = isPal(i,i+1,s);
            
            l = max(l1,l2);
            if(l > res_len)
            {
                res_len = l;
                st_idx = i - (l-1)/2;
            }
        }
        return s.substr(st_idx,res_len);
    }
};