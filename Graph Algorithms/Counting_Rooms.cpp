#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &a, vector<vector<int>> &vis, int curx, int cury,int n,int m )
{
    vis[curx][cury]=1;
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    for( int i=0 ; i<4 ; i++ )
    {
        int x=curx+dx[i];
        int y=cury+dy[i];
        if(x<0 || y<0 || x>=n || y>=m || a[x][y]=='#' || vis[x][y])
        continue;
        dfs(a,vis,x,y,n,m);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char> (m));
    for( int i=0 ; i< n ; i++ )
    {
        for( int j=0 ; j< m ; j++ )
        {
            cin>>a[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int> (m,0));
    // for( int i=0 ; i< m ; i++ )
    // {
    //     if(a[0][i]=='.' && !vis[0][i])
    //     dfs(a,vis,0,i,n,m);
    //     else if(a[n-1][i]=='.' && !vis[n-1][i])
    //     dfs(a,vis,n-1,i,n,m);
    // }
    // for( int i=0 ; i< n ; i++ )
    // {
    //     if(a[i][0]=='.' && !vis[i][0])
    //     dfs(a,vis,i,0,n,m);
    //     else if(a[i][m-1]=='.' && !vis[i][m-1])
    //     dfs(a,vis,i,m-1,n,m);
    // }
    int ans=0;
  
    for( int i=0 ; i< n ; i++ )
    {
        for( int j=0 ; j< m ; j++ )
        {
            if(a[i][j]=='.' && !vis[i][j])
            {
                dfs(a,vis,i,j,n,m);
                ans++;
            }
        }
    }
    cout<<ans;
    

}