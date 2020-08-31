class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
      int c=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            c=0;
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j]==1)
                    c++;
                else
                    c=0;
                mat[i][j]=c;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int min_width=mat[i][j];
                for(int k=i;k<n;k++)
                {
                    if(mat[k][j]==0)
                        break;
                    min_width=min(min_width,mat[k][j]);
                    cnt+=min_width;
                }
            }
        }
        return cnt;
        
    }
};