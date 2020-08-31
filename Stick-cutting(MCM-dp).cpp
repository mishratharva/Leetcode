class Solution {
public:
    int dp[102][102];
    
    int helper(int l,int r,vector<int>&cuts)
    {
        if(r-l<=1)
            return 0;
        else if (dp[l][r]!=-1)
            return dp[l][r];
        else
        {
            int ans=INT_MAX;
            
            for(int i=l+1;i<r;i++)
                ans=min(ans,helper(l,i,cuts)+helper(i,r,cuts)+cuts[r]-cuts[l]);
        return dp[l][r]=ans;
        }
    }
    int minCost(int N, vector<int>& cuts) {
  
        cuts.push_back(0);
        cuts.push_back(N);
        sort(cuts.begin(),cuts.end());
        int n=cuts.size();
        memset(dp,-1,sizeof(dp));
         int ans= helper(0,n-1,cuts);
      return ans;
        
    }
};