#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for( int i=0 ; i< m ;i++ )
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue< pair<int,int>> q;
    q.push({0,1});
    vector<int> vis(n+1,0);
    vector<int> hash(n+1,0);
    hash[1]=1;
    bool found=false;
    vis[1]=1;
    while (!q.empty() && !found)
    {
        int curdis=q.front().first;
        int node=q.front().second;
        q.pop();
        for( auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;   
                q.push({curdis+1,it});
                hash[it]=node;
                if(it==n)
                {found=true;
                break; }
            }
        }
    }
    if(found)
    {
        stack<int> st;
        st.push(n);
        int i=n;
        while( i!=1)
        {
            st.push(hash[i]);
            i=hash[i];
        }
        cout<<st.size()<<endl;
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    else cout<<"IMPOSSIBLE\n";
    

}