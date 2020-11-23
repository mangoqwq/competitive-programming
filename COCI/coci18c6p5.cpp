#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7, seed=131, MAXN=301, MAXM=2e3+1;

int curr[MAXN][MAXM], last[MAXN][MAXM];
set<int> fact={0};
int idx[MAXM*MAXM];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, N; cin >> n >> m >> N; N--;
    for (int i=1;i<=N;++i) fact.insert(N/i);
    int p=0;
    for (int x:fact) idx[x]=p++;
    curr[1][idx[N]]=1;
    for (int i=1;i<=n;++i){
        swap(last,curr);
        ms(curr,0);
        for (int j=1,a;j<=m;++j){
            cin >> a;
            for (int x:fact){
                curr[j][idx[x/a]]+=last[j][idx[x]], curr[j][idx[x/a]]%=mod;
                curr[j][idx[x/a]]+=curr[j-1][idx[x]], curr[j][idx[x/a]]%=mod;
            }
        }
    }
    cout << curr[m][0] << '\n';
}