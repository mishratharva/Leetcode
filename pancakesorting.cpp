class Solution {
public:
    int maxval(vector<int>&a ,int n)
    {
        int mx=a[0],mxi=0;
        for(int i=0;i<=n;i++)
        {
            if(a[i]>mx)
            {
                mx=a[i];
                mxi=i;
            }
        }
        return mxi;
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int>v;
        int n=A.size();
      for(int i=n-1;i>=0;i--)
      {
          int x=maxval(A,i);
          v.push_back(x+1);
          v.push_back(i+1);
          reverse(A.begin(),A.begin()+x+1);
           reverse(A.begin(),A.begin()+i+1);
          
      }
        return v;
    }
};