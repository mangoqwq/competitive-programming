#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

map<int, int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        int h; cin >> h;
        cnt[h]++;
    }
    for (int i = 1; i <= M; ++i){
        int t; cin >> t;
        auto it = cnt.upper_bound(t);
        if (it == cnt.begin()){
            cout << -1 << '\n';
        }
        else{
            cout << (--it)->first << '\n';
            it->second--;
            if (it->second == 0) cnt.erase(it);
        }
    }
}
