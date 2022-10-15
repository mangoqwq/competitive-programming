#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

struct Coord{
    int r,c;
    bool operator<(const Coord &a) const{
        return make_pair(a.r,a.c) < make_pair(r,c);
    }
};

set<int> s[MAXN+2];
bool vis[MAXN];
int maxr,maxc,minr,minc;
map<Coord,int> m;

void dfs(int r,int c){
    vis[m[{r,c}]]=1;
    minr=min(r,minr); maxr=max(r,maxr);
    minc=min(c,minc); maxc=max(c,maxc);
    if (s[r].count(c+1)) if (!vis[m[{r,c+1}]]) dfs(r,c+1);
    if (s[r].count(c-1)) if (!vis[m[{r,c-1}]]) dfs(r,c-1);
    if (s[r+1].count(c)) if (!vis[m[{r+1,c}]]) dfs(r+1,c);
    if (s[r-1].count(c)) if (!vis[m[{r-1,c}]]) dfs(r-1,c);
    if (s[r-1].count(c-1)) if (!vis[m[{r-1,c-1}]]) dfs(r-1,c-1);
    if (s[r-1].count(c+1)) if (!vis[m[{r-1,c+1}]]) dfs(r-1,c+1);
    if (s[r+1].count(c-1)) if (!vis[m[{r+1,c-1}]]) dfs(r+1,c-1);
    if (s[r+1].count(c+1)) if (!vis[m[{r+1,c+1}]]) dfs(r+1,c+1);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int rows,cols,n; cin >> rows >> cols >> n;
    for (int i=1,r,c;i<=n;++i){
        cin >> r >> c;
        s[r].insert(c);
        m[{r,c}]=i;
    }
    Coord curr;
    for (auto x:m){
        curr=x.first;
        if(!(curr.c==1||curr.r==rows)) continue;
        if (!vis[m[curr]]){ 
            minr=maxr=curr.r; minc=maxc=curr.c;
            dfs(curr.r,curr.c);
            if ((minr==1&&maxr==rows)||(minc==1&&maxc==cols)){ cout << "NO" << '\n'; return 0; }
            if ((minr==1&&minc==1)||(maxr==rows&&maxc==cols)){ cout << "NO" << '\n'; return 0; }
        }
    }
    cout << "YES" << '\n'; return 0;
}