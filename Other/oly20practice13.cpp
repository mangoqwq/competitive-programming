#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

priority_queue<int> q;
ll ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, a; cin >> n >> a;
    q.push(a-1);
    for (int i=2;i<=n;++i){
        cin >> a; a-=i;
        if (q.top()>a) ans+=q.top()-a, q.pop(), q.push(a), q.push(a);
        else q.push(a);
    }
    cout << ans << '\n';
}