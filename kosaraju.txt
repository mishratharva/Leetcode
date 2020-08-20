#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
#define pb push_back
bool visited[1000001];
vector<int>a[1000001];
vector<int>transpose[1000001];
stack<int>st;


 
void dfs(int node) // function to sort nodes based on their finish time
{
    visited[node]=true;
    for(int child:a[node])
    {
        if(!visited[child])
        dfs(child);
    }
    st.push(node);
}


void dfs2(int node) // dfs
{
    visited[node]=true;
    // cout<<node<<" "; 
    for(auto child:transpose[node])
    {
        if(!visited[child])
        dfs2(child);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        a[u].pb(v);
    }


    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++)  // for building stack according to finish time
    {
    if(!visited[i])
    dfs(i);
    }


    for(int i=0;i<n;i++)        //creating transpose of graph(i.e. flipping edges)
    {
        for(auto it:a[i])
        transpose[it].push_back(i);
    }
     memset(visited,false,sizeof(visited));

     int cc=0;
     while(!st.empty())    //visiting stack to find SCC
     {
         int ind=st.top();
         st.pop();
         if(!visited[ind])
         {
        cc++;
         dfs2(ind);
         }
     }
    cout<<cc<<endl; 


    for(int i=0;i<n;i++)    
    {
        a[i].clear();
        transpose[i].clear();
    }
    }

    
    return 0;
}
