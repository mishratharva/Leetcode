lass Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& a){
        int n=a.size();
       vector<int>res(n);
        pair<int,int>pos[n];
        auto endpos=pos+n;
        for(int i=0;i<n;i++)
        {
            pos[i]={a[i][0],i};
        }
        
        sort(pos,pos+n);
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(pos,pos+n,a[i][1],[](auto it,int val){return it.first<val;});
            if( it==endpos)
                res[i]=-1;
            else
                res[i]=(it->second);
         }
        return res;
    }
};