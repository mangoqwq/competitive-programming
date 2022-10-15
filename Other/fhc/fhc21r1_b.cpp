#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
#endif
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase){
        cout << "Case #" << testcase << ": ";
        int N, M, A, B; cin >> N >> M >> A >> B;
        int path = N + M - 2;
        if (min(A, B) <= path){
            cout << "Impossible" << '\n';
            continue;
        }
        cout << "Possible" << '\n';
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= M; ++j){
                if (i == 1 && j == M){
                    cout << B - path << " ";
                    assert(B - path <= 1000);
                }
                else if (i == N && j == M){
                    cout << A - path << " ";
                    assert(A - path <= 1000);
                }
                else if (i == 1 || i == N || j == 1) cout << 1 << " ";
                else cout << 1000 << " ";
            }
            cout << '\n';
        }
    }
}
