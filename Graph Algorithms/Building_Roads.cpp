#include<bits/stdc++.h>
using namespace std;
class dsu{
    public:
    vector<int> rank,parent,size;
    dsu(int n)
    {
        rank.resize( n+1 , 0 );
        size.resize( n+1 , 1 );
        parent.resize( n+1 );

        for( int i=0 ; i <= n ; i++ )
        parent[i] = i;
    }
    int findparent(int node)
    {
        if( node == parent[node] )
        return node;
        return parent[node] = findparent( parent[node] );
    }
    void unionbyrank( int node1, int node2 )
    {
        int x = findparent( node1 );
        int y = findparent( node2 );
        if( x == y )
        return;
        else
        {
            if( rank[y] < rank[x] )
            {
                parent[y] = x;
            }
            else if( rank[y] > rank[x] )
            {
                parent[x] = y;
            }
            else 
            {
                parent[x] = y;
                rank[y]++;
            }
        }
        return;
    }
    void unionbysize( int node1 , int node2)
    {
        int x=findparent(node1);
        int y=findparent(node2);
        if( x== y)
        return;
        if( size[x] > size[y] )
        {
            parent[y]=x;
            size[x]+=size[y];
        }
        else if( size[x] <= size[y] )
        {
            parent[x]=y;
            size[y]+=size[x];
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    dsu ds(n);
    for( int i=0 ;i< m ;i++ )
    {
        int x,y;
        cin>>x>>y;
        ds.unionbyrank(x,y);
    }
    int prev=-1;
    vector<pair<int,int>> ans;
    for( int i=1 ; i<= n ; i++ )
    {
        if(ds.findparent(i)==i)
        {
            if(prev!=-1)
            ans.push_back({prev,i});
            prev=i;
        }
    }
    cout<<ans.size()<<endl;
    for( auto [a,b] : ans)
    {
        cout<<a<<" "<<b<<endl;
    }

}