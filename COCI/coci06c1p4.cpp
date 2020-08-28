#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=52;

char arr[MAXN][MAXN],nxt[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct Coord{ int x,y; } s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c; cin >> r >> c;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> arr[i][j]; nxt[i][j]=arr[i][j];
            if (arr[i][j]=='X') vis[i][j]=1;
            if (arr[i][j]=='S') s={i,j};
        }
    }
    queue<Coord> q; q.push(s); int cnt=0;
    while (!q.empty()){
        int qsize=q.size();
        for (int i=1;i<=qsize;++i){
            int x=q.front().x, y=q.front().y; q.pop();
            if (x>r||x<1||y>c||y<1) continue;
            if (arr[x][y]=='D'){ cout << cnt << '\n'; return 0; }
            if (arr[x][y]=='*') continue;
            if (!vis[x+1][y]) vis[x+1][y]=1, q.push({x+1,y});
            if (!vis[x-1][y]) vis[x-1][y]=1, q.push({x-1,y});
            if (!vis[x][y+1]) vis[x][y+1]=1, q.push({x,y+1});
            if (!vis[x][y-1]) vis[x][y-1]=1, q.push({x,y-1});
        }
        for (int i=1;i<=r;++i){
            for (int j=1;j<=c;++j){
                if (arr[i][j]=='D'||arr[i][j]=='X') continue;
                if (arr[i+1][j]=='*') nxt[i][j]='*';
                if (arr[i-1][j]=='*') nxt[i][j]='*';
                if (arr[i][j+1]=='*') nxt[i][j]='*';
                if (arr[i][j-1]=='*') nxt[i][j]='*';
            }
        }
        swap(nxt,arr);
        ++cnt;
    }
    cout << "KAKTUS" << '\n';



}