#include<bits/stdc++.h>
using namespace std;
string dfs(int i,int j,vector<vector<char>> &a , int ti, int tj, string &ans, int n , int m )
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
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<char>> a(n, vector<char> (m));
    pair<int,int> chara,charb;
    vector<vector<int>> vis(n, vector<int> (m,0));
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    for( int i=0 ;i< n ;i++ )
    {
        for( int j=0  ; j<m ; j++ )
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
            { chara={i,j}; vis[i][j]=1; }
            if(a[i][j]=='B')
            charb={i,j};
        }
    }
    string ans="";
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{chara.first, chara.second}});
    bool found=false;
    while (!q.empty() && !found)
    {
        int curx=q.front().second.first;
        int cury=q.front().second.second;
        int dis=q.front().first;
        q.pop();
        vector<char> direction={'D','U','R','L'};
        for( int i=0 ; i< 4 ;i++ )
        {
            int x=curx+dx[i];
            int y=cury+dy[i];
            if(x<0 || y<0 || x>=n || y>=m || a[x][y]=='#' || vis[x][y])
            continue;
            vis[x][y]=1;
            a[x][y]=direction[i];
            if(x==charb.first && y==charb.second )
            {
                found=true; break;
            }
            q.push({dis+1,{x,y}});
        }
    }

    for( int i=0 ; i< n ;i++ )
    {
        for( int j=0 ; j< m ; j++ )
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    if(found)
    {
        ans=dfs(charb.first, charb.second , a , chara.first,chara.second,ans, n,m);
        reverse(ans.begin() , ans.end()) ;
        cout<<"YES\n";
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    else cout<<"NO\n";
}