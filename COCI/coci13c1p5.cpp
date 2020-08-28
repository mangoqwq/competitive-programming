#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXK=2'000'001;

int freq[MAXK];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a;i<=n;++i){
        cin >> a; freq[a]++;
    }
    ll ans=-1;
    for (int i=1;i<MAXK;++i){
        int cnt=0;
        for (int j=i;j<MAXK;j+=i) cnt+=freq[j];
        if (cnt>=2) ans=max(ans,1LL*cnt*i);
    }
    cout << ans << '\n';
}