#include<bits/stdc++.h>
using namespace std;
#define ppi pair<int,pair<int,int>>
int n,m;
bool isvalid( int x, int y )
{
    return !(x<0 || y<0 || x>=n || y>=m );
}
void dikstra(vector<vector<char>> &a ,vector<vector<int>> &dism , queue< ppi>&pq )
{
    while( !pq.empty())
    {
        int d=pq.front().first;
        int xx=pq.front().second.first;
        int yy=pq.front().second.second;
        pq.pop();
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        if( d>dism[xx][yy])
        continue;
        for( int i=0 ; i< 4 ; i++ )
        {
            int x=xx+dx[i];
            int y=yy+dy[i];
            if( !isvalid(x,y) || a[x][y]=='#') continue; 
            if( d+1 < dism[x][y] )
            {
                dism[x][y]=d+1;
                pq.push({d+1, { x,y}});
            }
        }

    }
}
string ans="";
int ti,tj;
void travel( vector<vector<char>> &a, int i, int j )
{
    while(i!=ti || j!=tj )
    {
        if(a[i][j]=='U')
        {
            ans.push_back('U');
            i++;
        }
        else if(a[i][j]=='R' )
        {
            ans.push_back('R');
            j--;
        }
        else if( a[i][j]=='L')
        {
            ans.push_back('L');
            j++;
        }
        else if(a[i][j]=='D') {ans.push_back('D'); i--; }
    }
    
}
bool dikstraa(vector<vector<char>> &a ,vector<vector<int>> &dism ,queue< ppi> &pq )
{
    while( !pq.empty())
    {
        int d=pq.front().first;
        int xx=pq.front().second.first;
        int yy=pq.front().second.second;
        pq.pop();
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        vector<char> ch={'D','U','R','L'};
        if( d>dism[xx][yy])
        continue;
        for( int i=0 ; i< 4 ; i++ )
        {
            int x=xx+dx[i];
            int y=yy+dy[i];
            if( !isvalid(x,y)) {
                // a[x][y]=ch[i];
                travel(a,xx,yy);
                return true;
                }
            if( a[x][y]=='#') continue; 
            if( d+1 < dism[x][y] )
            {
                dism[x][y]=d+1;
                a[x][y]=ch[i];
                pq.push({d+1, { x,y}});
            }
        }
    }
    return false;
}
int main()
{
    int x,y;
    cin>>x>>y;
    n=x;m=y;
    vector<vector<char>> a(n,vector<char> (m));
    vector<vector<int>> dism(n,vector<int> (m,1e9));
    vector<vector<int>> dis(n,vector<int> (m,1e9));
    queue<ppi> pq,pq1;
    for( int i=0 ; i< x  ; i++ )
    {
        for( int j=0 ; j< y ; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='M')
            { dism[i][j]=0; pq.push({0,{i,j}}); }
            else if( a[i][j]=='A')
            { pq1.push({0,{i,j}}); ti=i; tj=j; }
        }
    }
    dikstra(a,dism,pq);
    pq=pq1;
    bool check=dikstraa(a,dism,pq);
    if(check)
    {
        cout<<"YES\n";
        cout<<ans.size()<<endl;
        reverse(ans.begin() , ans.end());
        cout<<ans<<endl;
        // printpath()
    }
    else {
        cout<<"NO\n";
    }


}