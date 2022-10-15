#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6;

int h[MAXN], arr[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> h[i];
    for (int i=1;i<=n;++i) cin >> arr[i];
    deque<int> q;
    for (int i=n;i>=1;--i){
        while (!q.empty()&&q.front()<=h[i]) q.pop_front();
        q.push_front(h[i]);
        if (arr[i]>q.size()-1) ans[i]=-1;
        else ans[i]=q[arr[i]];
    }
    for (int i=1;i<=n;++i) cout << ans[i] << " ";
    cout << '\n';
}