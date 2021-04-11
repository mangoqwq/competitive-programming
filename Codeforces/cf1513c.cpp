#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5;

ll ans[10][MAXN];
ll lst[10], cnt[10];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int c=0;c<=9;++c){
        ms(cnt,0), cnt[c]=1;
        for (int i=1;i<=MAXN;++i){
            swap(lst,cnt);
            for (int j=1;j<=9;++j) cnt[j]=lst[j-1];
            cnt[0]=lst[9], cnt[1]+=lst[9];
            for (int j=0;j<=9;++j) cnt[j]%=mod;
            ans[c][i]=accumulate(cnt,cnt+10,0LL)%mod;
        }
    }
    while (t--){
        ms(cnt,0);
        string s; cin >> s;
        int n; cin >> n;
        ll res=0;
        for (int x:s) res+=ans[x-'0'][n];
        cout << res%mod << '\n';
    }
}