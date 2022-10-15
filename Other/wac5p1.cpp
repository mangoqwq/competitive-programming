#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

int cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a;i<=n;++i){
        cin >> a; cnt[a]++;
    }
    ll tot=0; int uwu=0;
    for (int i=MAXN-1;i>=1;--i){
        if (cnt[i]>uwu) tot+=i*(cnt[i]-uwu), uwu=cnt[i];
    }
    cout << tot << '\n';
}