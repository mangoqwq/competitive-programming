#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
#define s second
#define f first
const int mod=13371337, seed=131, MAXN=15;

bool adj[MAXN][MAXN];
int cnt[MAXN][(1<<15)];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        ms(cnt,0);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                cin >> adj[i][j];
            }
        }
        queue<pii> q; q.push({0,1}); cnt[0][1]=1;
        while (!q.empty()){
            int curr=q.front().f, mask=q.front().s; q.pop();
            for (int i=0;i<n;++i){
                if (adj[curr][i]&&!(1&(mask>>i))){
                    if (!cnt[i][(1<<i)+mask]) q.push({i,(1<<i)+mask});
                    cnt[i][(1<<i)+mask]+=cnt[curr][mask];
                    cnt[i][(1<<i)+mask]%=mod;
                }
            }
        }
        int ans=0;
        for (int i=0;i<(1<<15);++i) ans+=cnt[n-1][i], ans%=mod;
        cout << ans << '\n';
    }
}