class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        if(n==0)
            return 0;
        int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                    dp[i]=max((dp[j]+1),dp[i]);
            }
        }
        
        int mx=0;
        for(int i=0;i<=n;i++)
            mx=max(dp[i],mx);
        return mx;
    }
};