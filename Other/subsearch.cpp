#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int a[MAXN], cnt[MAXN];
set<int> l[MAXN];
int curr; ll tot;

void ins(int x){
    if (l[cnt[x]].count(x)) l[cnt[x]].erase(x);
    cnt[x]++;
    l[cnt[x]].insert(x);
    curr=max(curr,cnt[x]);
}

void rem(int x){
    l[cnt[x]].erase(x);
    if (l[cnt[x]].empty()&&cnt[x]==curr) curr--;
    cnt[x]--;
    l[cnt[x]].insert(x);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, f; ll s; cin >> n >> f >> s;
    ll good=0, great=0, gg=0;
    int p1=1, p2=1;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        tot+=a[i];
        ins(a[i]);
        while (curr>f) rem(a[p1++]);
        while (tot>s) tot-=a[p2++];
        good+=i-p1+1; good%=mod;
        great+=i-p2+1; great%=mod;
        gg+=min(i-p1+1,i-p2+1); gg%=mod;
    }
    // cout << good << " " << great << " " << gg << '\n';
    cout << good*great%mod*gg%mod << '\n';
}