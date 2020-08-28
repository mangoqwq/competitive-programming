#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3e4+1;

int dist[MAXN],p[MAXN],b[MAXN];
bool vis[MAXN];
vector<int> arr[MAXN];
unordered_set<int> no;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0;i<m;++i){
        cin >> b[i] >> p[i];
        arr[b[i]].push_back(i);
    }
    ms(dist,0x3f);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int x:arr[b[0]]) pq.push({0,x});
    dist[b[0]]=0;
    while (!pq.empty()){
        int curr=pq.top().s, d=pq.top().f; pq.pop();
        if (vis[curr]) continue;
        vis[curr]=1;
        no.clear();
        for (int i=b[curr],cd=d;i<=n;i+=p[curr],++cd){
            if (cd>=dist[i]) continue;
            dist[i]=cd;
            for (int x:arr[i]){
                if (!no.count(p[x])) pq.push({cd,x}), no.insert(p[x]);
            }
        }
        no.clear();
        for (int i=b[curr],cd=d;i>=0;i-=p[curr],++cd){
            if (cd>=dist[i]) continue;
            dist[i]=cd; 
            for (int x:arr[i]){
                if (!no.count(p[x])) pq.push({cd,x}), no.insert(p[x]);
            }
        }
    }
    cout << (dist[b[1]]==0x3f3f3f3f?-1:dist[b[1]]) << '\n';
}