#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

struct Point{
    int x, y;
    bool operator<(const Point &other) const{ return x < other.x; }
} w[MN], b[MN];
set<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        cin >> w[i].x >> w[i].y;
    }
    for (int i = 1; i <= N; ++i){
        cin >> b[i].x >> b[i].y;
    }
    sort(w + 1, w + 1 + N);
    sort(b + 1, b + 1 + N);
    int p = 1;
    for (int i = 1; i <= N; ++i){
        while (p <= N && w[p].x < b[i].x) s.insert(w[p++].y);
        auto it = s.lower_bound(b[i].y);
        if (it == s.begin()) continue;
        s.erase(--it); ans++;
    }
    cout << ans << '\n';
}
