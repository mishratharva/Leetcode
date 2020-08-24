class Solution {
public:
     
    int maxCoins(vector<int>& a) {
        int n=a.size();
        a.insert(a.begin(),1);
        a.insert(a.end(),1);
        int N=a.size();
        int dp[N][N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                dp[i][j]=0;
        }
        
        for(int len=1;len<=n;len++) //window size
        {
            for(int left=1;left<=n-len+1;left++)
            {
                int right=left+len-1;
                for(int i=left;i<=right;i++)
                    dp[left][right]=max(dp[left][right],(dp[left][i-1]+dp[i+1][right]+(a[left-1]*a[i]*a[right+1])));
            }
        }
        return dp[1][n];
    }
};