#include <bits/stdc++.h>

// THIS ISN'T SUPPOSED TO PASS
// THIS ISN'T SUPPOSED TO PASS
// THIS ISN'T SUPPOSED TO PASS
// THIS ISN'T SUPPOSED TO PASS

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1501;
vector<int> graph[MAXN];
bitset<MAXN> vis;
int q[MAXN], p1, p2, p3;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i=0,a,b;i<m&&i<23075;++i){
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    for (int curr=1;curr<=n;++curr){
        vis.reset(); vis[curr]=1;
        q[1]=curr;
        p1=p2=p3=1;
        for (int c=1;c<=k;++c){
            for (int i=p1;i<=p2;++i){
                int v=q[i];
                for (int x:graph[v]){
                    if (!vis[x]){
                        vis[x]=1;
                        q[++p3]=x;
                    }
                }
            }
            p1=p2+1; p2=p3;
        }
        cout << vis.count() << '\n';
    }
}