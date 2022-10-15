#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=201;

struct Edge{ int n,id; };
struct Item{ int a,b; } arr[MAXN];
int dist[MAXN],n,m,k,q;
vector<Edge> graph[MAXN];

int check(int id){
    int tot=0;
    for (int i=1;i<=q;++i){
        ms(dist,-1); dist[arr[i].a]=0;
        queue<int> q; q.push(arr[i].a);
        int cnt=1;
        while (!q.empty()){
            int qsize=q.size();
            for (int j=1;j<=qsize;++j){
                int curr=q.front(); q.pop();
                for (Edge x:graph[curr]){
                    if (x.id!=0&&x.id!=id) continue;
                    if (dist[x.n]!=-1) continue;
                    dist[x.n]=cnt; q.push(x.n);
                }
            }
            cnt++;
        }
        tot+=dist[arr[i].b];
    }
    return tot;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back({b,0});
        graph[b].push_back({a,0});
    }
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }
    for (int i=1;i<=q;++i){
        cin >> arr[i].a >> arr[i].b;

    }
    if (k==0){
        cout << check(0) << '\n';
    }
    if (k==1){
        int ans=0x3f3f3f3f;
        for (int i=1;i<=m;++i){
            ans=min(ans,check(i));
        }
        cout << ans << '\n';
    }
}