class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int left=0,right=-1,c=0;
        int sum=0;
        unordered_map<int,int>dp;
        dp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(dp.count(sum-target))
            {
                int left=dp[sum-target];
                if(right<=left)
                {
                    c++;
                    right=i;
                }
            }
            dp[sum]=i;
        }
        return c;
    }
};