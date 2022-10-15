#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, inf=0x3f3f3f3f, MAXN=1e6+1;

int dist[MAXN], ans=inf, high;
queue<int> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(dist,0x3f);
    int h, j, n; cin >> h >> j >> n;
    for (int i=1;i<=n;++i){
        int a, b; cin >> a >> b;
        for (int j=a;j<=b;++j) dist[j]=-1;
    }
    dist[0]=0; q.push(0);
    while (!q.empty()){
        int v=q.front(); q.pop();
        if (v+j>=h) ans=min(ans,dist[v]+1);
        else if (dist[v]+1<dist[v+j]) dist[v+j]=dist[v]+1, q.push(v+j);
        for (int i=v;i>=high;--i){
            if (dist[v]+1<dist[i]) dist[i]=dist[v]+1, q.push(i);
        }
        high=max(high,v);
    }
    cout << (ans==inf?-1:ans) << '\n';
}