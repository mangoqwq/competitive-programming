#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Edge{int r,c,prev;} adj[32'000'010];
int head[16'000'001], idx; 
bool vis[4001][4001];
bool has[16'000'001];
vector<vector<int>> room;

void dfs(pii c){
    vis[c.f][c.s]=1;
    for (int x=head[room[c.f][c.s]];x>=0;x=adj[x].prev){
        if (vis[adj[x].r][adj[x].r]) continue;
        else dfs({adj[x].r,adj[x].c}); 
    }
}

bool can_escape(int r, int c, vector<vector<int>> v){
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            has[v[i][j]]=1;
        }
    }
    ms(head,-1);
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            if (has[i*j]) adj[idx]={i,j,head[i*j]}, head[i*j]=idx++;
        }
    }
    room=v;
    dfs({1,1});
    return (vis[r][c]);
}

int main(){
    // vector<vector<int>> uwu={{0,0,0,0,0},{0,3,10,8,14},{0,1,11,12,12},{0,6,2,3,9}};
    // cout << (can_escape(3, 4, uwu)? "yes":"no") << '\n';
}