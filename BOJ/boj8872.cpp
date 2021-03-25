#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int n, m, l, a[MAXN], b[MAXN], t[MAXN];
struct Edge{ int n,w,last; } graph[2*MAXN];
int head[MAXN],idx=1;
bool vis[MAXN];
int maxd, far, last[MAXN], dist[MAXN], ans;
vector<int> radii;

void dfs(int curr, int prev, int d){
    vis[curr]=1;
    last[curr]=prev, dist[curr]=d;
    if (d>maxd) maxd=d, far=curr;
    for (int i=head[curr];i!=0;i=graph[i].last){
        Edge x=graph[i];
        if (x.n==prev) continue;
        dfs(x.n,curr,d+x.w);
    }
}

int travelTime(){
    for (int i=0;i<m;++i){
        graph[idx]={b[i],t[i],head[a[i]]}, head[a[i]]=idx++;
        graph[idx]={a[i],t[i],head[b[i]]}, head[b[i]]=idx++;
    }
    for (int i=0;i<n;++i){
        if (vis[i]) continue;
        maxd=-1, dfs(i,-1,0);
        maxd=-1, dfs(far,-1,0);
        int radius=INT_MAX;
        for (int i=far;i!=-1;i=last[i]){
            radius=min(radius,max(maxd-dist[i],dist[i]));
        }
        ans=max(ans,maxd);
        radii.push_back(radius);
    }
    sort(radii.begin(),radii.end(),greater<int>());
    if (radii.size()>=2) ans=max(ans,radii[0]+radii[1]+l);
    if (radii.size()>=3) ans=max(ans,radii[1]+radii[2]+2*l);
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> l;
    for (int i=0;i<m;++i) cin >> a[i] >> b[i] >> t[i];
    cout << travelTime() << '\n';
}