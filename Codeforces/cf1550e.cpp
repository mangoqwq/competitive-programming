#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n, k, psa[MAXN][17], que[MAXN];
int link[MAXN][17], dist[1<<17];
string s;

int valid(int i, int sz, int c){
    if (i<sz) return 0;
    return (que[i]-que[i-sz]+psa[i][c]-psa[i-sz][c])==sz;
}

struct Item{
    int v, d;
    bool operator<(const Item &x) const{
        return d<x.d;
    }
};
bool check(int sz){
    if (sz==0) return 1;
    ms(link,-1);
    for (int i=1;i<=n;++i){
        for (int j=0;j<k;++j){
            if (valid(i,sz,j)) link[i][j]=i-sz;
            else link[i][j]=link[i-1][j];
        }
    }
    priority_queue<Item> pq;
    ms(dist,-1);
    dist[0]=n; pq.push({0,n});
    while (!pq.empty()){
        int v=pq.top().v; pq.pop();
        int i=dist[v];
        for (int j=0;j<k;++j){
            if (link[i][j]==-1) continue;
            int to=v|(1<<j);
            if (dist[to]>=link[i][j]) continue;
            dist[to]=link[i][j];
            pq.push({to,dist[to]});
        }
    }
    return dist[(1<<k)-1]!=-1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("txt.in","r",stdin);
    cin >> n >> k;
    cin >> s; s=" "+s;
    for (int i=1;i<=n;++i){
        if (s[i]=='?') que[i]++;
        else psa[i][s[i]-'a']++;
        for (int j=0;j<k;++j) psa[i][j]+=psa[i-1][j];
        que[i]+=que[i-1];
    }
    int lo=0, hi=n;
    while (lo<hi){
        int mid=(lo+hi+1)>>1;
        if (check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout << lo << '\n';
}
