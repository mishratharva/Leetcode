class Solution {
public:
   unordered_map<int,int>dp;
    int helper(int n)
    {
        int res=0;
        if(n<=2)
         return n;
        else if(dp[n]!=0)
            return dp[n];
        else
        {
            res=1+min((n%2+helper(n/2)),(n%3+helper(n/3)));
            return dp[n]=res;
        }
    }
    int minDays(int n) {
    int ans= helper(n);
        return ans;
    }
};