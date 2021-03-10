#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

unordered_map<int,int> m[MAXN], f[MAXN];
int h[MAXN];
ll ans=1;

void go(int idx, int &val, int i){
    if (val==1) return;
    int cnt=0;
    while (val%i==0) cnt++, val/=i;
    if (!cnt) return;
    int tmp=(f[idx].count(i)?f[idx][i]:0);
    m[i][tmp]--;
    if (m[i][tmp]==0) m[i].erase(tmp);
    f[idx][i]+=cnt;
    m[i][f[idx][i]]++;
    while (!m[i].count(h[i])){
        h[i]++;
        ans=ans*i%mod;
    }
}

void ins(int idx, int val){
    for (int i=2;i*i<=val;++i){
        go(idx,val,i);
    }
    go(idx,val,val);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<MAXN;++i) m[i][0]=n;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        ins(i,x);
    }    
    while (q--){
        int i, x; cin >> i >> x;
        ins(i,x);
        cout << ans << '\n';
    }
}