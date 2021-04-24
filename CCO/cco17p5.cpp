#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

priority_queue<int,vector<int>,greater<int>> pq;
vector<int> c[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int a, b; cin >> a >> b;
        c[a].push_back(b);
    }
    int in=0, ans=0, left=n;
    for (int i=n;i>=0;--i){
        for (int x:c[i]) pq.push(x), left--;
        while (left+in<i) ans+=pq.top(), pq.pop(), in++;
    }
    cout << ans << '\n';
}