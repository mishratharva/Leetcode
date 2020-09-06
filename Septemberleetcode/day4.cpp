class Solution {
public:
    vector<int> partitionLabels(string S) {
    map<int,int>v;
        for(int i=0;i<S.size();i++)
            v[S[i]-'a']=i;
        int mx=-1,lst=0;
        vector<int>v1;
        for(int i=0;i<S.size();i++)
        {
            mx=max(mx,v[S[i]-'a']);
            if(mx==i)
            {
            v1.push_back(mx-lst+1); 
            lst=i+1;
            }
        }
        return v1;
    }
};