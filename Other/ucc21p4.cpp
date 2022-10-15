#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int a[MAXN], fib[MAXN];
int dist[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    fib[1]=1, a[1]=2;
    for (int i=2;i<=n;++i){
        fib[i]=(fib[i-2]+fib[i-1])%2021;
        a[i]=fib[i]+(i%50); 
        dist[i]=inf;
    }
    queue<int> q; q.push(1);
    while (!q.empty()){
        int v=q.front(); q.pop();
        if (dist[v]+1<dist[v-1]){
            dist[v-1]=dist[v]+1;
            q.push(v-1);
        }
        if (dist[v]+1<dist[v+1]){
            dist[v+1]=dist[v]+1;
            q.push(v+1);
        }
        if (dist[v]+1<dist[v+a[v]]){
            dist[v+a[v]]=dist[v]+1;
            q.push(v+a[v]);
        }
        if (v>a[v]&&dist[v]+1<dist[v-a[v]]){
            dist[v-a[v]]=dist[v]+1;
            q.push(v-a[v]);
        }
    }
    cout << dist[n] << '\n';
}