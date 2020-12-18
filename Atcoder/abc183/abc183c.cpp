#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=9;

int adj[MAXN][MAXN], arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            arr[i]=i;
            cin >> adj[i][j];
        }
    }
    int ans=0;
    do{
        int curr=0;
        for (int i=2;i<=n;++i){
            curr+=adj[arr[i]][arr[i-1]];
        }
        curr+=adj[arr[n]][1];
        ans+=curr==k;
    } while (next_permutation(arr+2,arr+1+n)); 
    cout << ans << '\n';
}