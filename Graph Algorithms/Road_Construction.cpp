#include<bits/stdc++.h>
using namespace std;
class dsu{
    
    public:
    vector<int> parent;
    vector<int> size;
    dsu(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for( int i=0 ; i<= n ; i++ )
        {
            parent[i]=i;
        }
    }
    int up( int node)
    {
        if(parent[node]==node)
        return node;
        return parent[node]=up(parent[node]);
    }
    void unionbysize(int i, int j)
    {
        int x=up(i);
        int y=up(j);
        if(x==y)
        return;
        if( size[x]> size[y])
        {
            parent[y]=x;
            size[x]+=size[y];
        }
        else {
            parent[x]=y;
            size[y]+=size[x];
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    int sz=1;
    int comp=n;
    dsu ds(n);
    for( int i=0 ; i< m ; i++ )
    {
        int x,y;
        cin>>x>>y;
        int a=ds.up(x);
        int b=ds.up(y);
        if( a==b)
        {
            sz=max(ds.size[a],sz);
            cout<<comp<<" "<<sz<<endl;
        }
        else
        {
            comp--;
            ds.unionbysize(x,y);
            sz=max(ds.size[ds.up(x)],sz);
            cout<<comp<<" "<<sz<<endl;
        }
    }
}