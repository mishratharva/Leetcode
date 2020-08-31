class Solution {
public:
    int _find(int x,vector<int>&parent)
    {
        if(parent[x]==-1)
            return x;
        else
         return parent[x]=_find(parent[x],parent);
    }
    void _union(int x,int y,vector<int>&parent)
    {
        int xp=_find(x,parent);
        int yp=_find(y,parent);
        if(xp!=yp)
            parent[xp]=yp;
    }
    int largestComponentSize(vector<int>& a) {
        vector<int>parent(1000001,-1);
      for(int i=0;i<a.size();i++)
      {
          for(int j=2;j*j<=a[i];j++)
          {
              if(a[i]%j==0)
              {
                  _union(a[i],j,parent);
                  _union(a[i],a[i]/j,parent);
              }
          }
      }
        int c=0;
        unordered_map<int,int>ans;
        for(int i=0;i<a.size();i++)
        {
            int xp=_find(a[i],parent);
            c=max(c,1+ans[xp]);
            ans[xp]+=1;
        }
        return c;
    }
};