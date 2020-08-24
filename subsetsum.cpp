class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n=a.size();
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum+=a[i];
        if(sum%2)
            return false;
        sum=sum/2;
       int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=sum;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
          for(int j=1;j<=sum;j++)
        {
            if(j<a[i-1])
                dp[i][j]=dp[i-1][j];
             else
                 dp[i][j]=(dp[i-1][j] || dp[i-1][j-a[i-1]]);
        }  
        }
        return dp[n][sum];
    }
};