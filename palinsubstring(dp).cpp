class Solution {
public:
    string longestPalindrome(string s) {
        string st="";
        int n=s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        int start=0,x=1;
      for(int i=0;i<n-1;i++)
      {
          if(s[i+1]==s[i])
          {
            dp[i][i+1]=1;
              start=i;
              x=2;
          }
      }
        for(int gap=3;gap<=n;gap++)
        {
            for(int i=0;i<n-gap+1;i++)
            {
                int j=i+gap-1;
                if(dp[i+1][j-1]==1 && s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(x<gap)
                    {
                        x=gap;
                        start=i;
                    }
                }
            }
        }
      st=s.substr(start,x);
        return st;
    }
};