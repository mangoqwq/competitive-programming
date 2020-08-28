#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

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

int travelTime(int n, int m, int l, int a[], int b[], int t[]){
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

// int main(){
//     //cin.tie(0)->sync_with_stdio(0);
//     int n=12,m=8,l=2;
//     int a[8]={0, 8, 2, 5, 5, 1, 1, 10},
//         b[8]={8, 2, 7, 11, 1, 3, 9, 6},
//         t[8]={4, 2, 4, 3, 7, 1, 5, 3};
//     cout << travelTime(n,m,l,a,b,t) << '\n';
// }