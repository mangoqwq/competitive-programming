#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

vector<int> graph[MAXN];
int deg[MAXN];
bool vis[MAXN];

bool cmp(int a, int b){
    return deg[a]>deg[b];
}
priority_queue<int,vector<int>,function<bool(int,int)>> pq(cmp);

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; t=5;
    while (t--){
        int n,ans=1; cin >> n;
        for (int i=0;i<n;++i) graph[i].clear(), deg[i]=0, vis[i]=0;
        for (int i=0,a,b;i<n-1;++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            deg[a]++; deg[b]++;
        }
        int curr;
        pq.push(0); vis[0]=1;
        while (!pq.empty()){
            curr=pq.top(); pq.pop();
            for (int x:graph[curr]){
                if (!vis[x]) vis[x]=1, pq.push(x);
            }
            ans=max(ans,(int)pq.size());
        }
        cout << ans << '\n';

    }
}