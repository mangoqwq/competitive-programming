#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    queue<int> q;
    map<int, int> cnt;
    ll ans = 0, cur = 0;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        cur++; q.push(a); cnt[a]++;
        while (cnt.size() > K){
            int v = q.front(); q.pop();
            cnt[v]--; cur--;
            if (cnt[v] == 0) cnt.erase(v);
        }
        ans += cur;
    }
    cout << ans << '\n';
}
