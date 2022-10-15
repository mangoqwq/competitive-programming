#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct House{
    int x, c;
bool operator<(const House &a) const{
        return x<a.x;
    }
} a[MAXN];
int ans, curr;
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    for (int i=1;i<=n;++i) cin >> a[i].x >> a[i].c;
    sort(a+1,a+1+n);
    for (int i=1;i<=n;++i){
        auto [x,c]=a[i];
        curr+=c; pq.push(c);
        while (!pq.empty()&&(int)pq.size()>(m-x*2)/t) curr-=pq.top(), pq.pop();
        ans=max(ans,curr);
    }
    cout << ans << '\n';
}