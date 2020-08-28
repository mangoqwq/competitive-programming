#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001,X=2e6;

ll psa[MAXN][MAXN],arr[MAXN],cnt[4'000'001];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            psa[i][j]+=cnt[-arr[i]-arr[j]+X];
            cnt[arr[j]+X]++;
        }
        for (int j=i+1;j<=n;++j){
            cnt[arr[j]+X]=0;
        } 
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            psa[i][j]=psa[i][j]+psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    for (int i=1,l,r;i<=q;++i){
        cin >> l >> r;
        cout << psa[r][r]-psa[l-1][r]-psa[r][l-1]+psa[l-1][l-1] << '\n';
    }
}