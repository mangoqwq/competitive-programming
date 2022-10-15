#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

priority_queue<int,vector<int>,greater<int>> q;
vector<int> t[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x, n; cin >> x >> n;
    for (int i=1;i<=n;++i){
        int l, r; cin >> l >> r;
        l=max(0,l-x);
        t[l].push_back(r);
    }
    int ans=0;
    for (int i=0;i<MAXN;++i){
        for (int x:t[i]) q.push(x);
        while (!q.empty()&&q.top()<i) q.pop();
        if (!q.empty()) ans++, q.pop();
    }
    cout << ans << '\n';
}