#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

int w[MAXN], ans[MAXN];
vector<int> adj[MAXN];
bool eve[MAXN][MAXN], woke[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int d; cin >> d;
    for (int i=1;i<=d;++i) cin >> w[i];
    int f; cin >> f;
    for (int i=1,a,b;i<=f;++i){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int t; cin >> t;
    eve[0][1]=1;
    for (int i=0;i<=t;++i){
        for (int a=1;a<=d;++a){
            if (!eve[i][a]) continue;
            ans[a]++;
            for (int b:adj[a]){
                if (woke[b]) continue;
                woke[b]=1;
                if (i+w[b]<=t) eve[i+w[b]][b]=1;
            }
        }
        for (int a=1;a<=d;++a){
            if (eve[i][a]) woke[a]=0;
        }
    }
    for (int i=1;i<=d;++i) cout << ans[i] << '\n';
}