class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
     int res=0;
        int cnt=0;
        int n=A.size();
        int m=A[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt=0;
                for(int r=0;r<n&&(i+r)<n;r++)
                {
                    for(int c=0;c<m&&(c+j)<m;c++)
                    {
                        if(B[r][c]==1 && A[i+r][j+c]==1)
                            cnt++;
                    }
                }
                res=max(res,cnt);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt=0;
                for(int r=0;r<n&&(i+r)<n;r++)
                {
                    for(int c=0;c<m&&(c+j)<m;c++)
                    {
                        if(A[r][c]==1 && B[i+r][j+c]==1)
                            cnt++;
                    }
                }
                res=max(res,cnt);
            }
        }
        return res;
    }
};