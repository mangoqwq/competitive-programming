#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int arr[MAXN], n;
bool vis[MAXN][81];
struct Pos{ int r, c; } s, e;
queue<Pos> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    cin >> s.r >> s.c >> e.r >> e.c;
    q.push({s.r,s.c}); int cnt=0,r,c;
    while (!q.empty()){
        int qsize=q.size();
        for (int i=1;i<=qsize;++i){
            r=q.front().r, c=q.front().c, q.pop();
            if (r<1||r>n) continue;
            if (r==e.r&&c==e.c){ cout << cnt << '\n'; return 0; }
            // left
            if (c==1){
                if (!vis[r-1][arr[r-1]]) vis[r-1][arr[r-1]]=1, q.push({r-1,arr[r-1]});
            }
            else{
                if (!vis[r][c-1]) vis[r][c-1]=1, q.push({r,c-1});
            }
            // right
            if (c==arr[r]){
                if (!vis[r+1][1]) vis[r+1][1]=1, q.push({r+1,1});
            }
            else{
                if (!vis[r][c+1]) vis[r][c+1]=1, q.push({r,c+1});
            }
            // up
            if (c>arr[r-1]){
                if (!vis[r-1][arr[r-1]]) vis[r-1][arr[r-1]]=1, q.push({r-1,arr[r-1]});
            }
            else{
                if (!vis[r-1][c]) vis[r-1][c]=1, q.push({r-1,c});
            }
            // down
            if (c>arr[r+1]){
                if (!vis[r+1][arr[r+1]]) vis[r+1][arr[r+1]]=1, q.push({r+1,arr[r+1]});
            }
            else{
                if (!vis[r+1][c]) vis[r+1][c]=1, q.push({r+1,c});
            }
        } cnt++;
    }
}