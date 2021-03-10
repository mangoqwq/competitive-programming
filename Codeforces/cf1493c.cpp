#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, k;
int cnt[26], add;

void upd(int x, int v){
    add-=(k-(cnt[x]%k))%k;
    cnt[x]+=v;
    add+=(k-(cnt[x]%k))%k;
}

void solve(){
    ms(cnt,0); add=0;
    cin >> n >> k;
    string s; cin >> s; s=" "+s;
    for (int i=1;i<=n;++i) s[i]=s[i]-'a', upd(s[i],1);
    if (n%k){ cout << -1 << '\n'; return; }
    if (add==0){ 
        for (int i=1;i<=n;++i) cout << (char)(s[i]+'a');
        cout << '\n';
        return;
    }
    for (int p=n;p>=1;--p){
        upd(s[p],-1);
        for (int i=s[p]+1;i<26;++i){
            upd(i,1);
            if (add<=n-p){
                s[p]=i;
                int idx=25;
                for (int j=n;j>p;--j){
                    while (idx&&cnt[idx]%k==0) idx--;
                    s[j]=idx; cnt[idx]++;
                }
                for (int j=1;j<=n;++j) cout << (char)(s[j]+'a');
                cout << '\n';
                return;
            }
            upd(i,-1);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
}