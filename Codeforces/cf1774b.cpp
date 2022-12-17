#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M, K; cin >> N >> M >> K;
        int big = (N+K)/K, cnt = N%K;
        bool good = 1;
        for (int i = 0; i < M; ++i){
            int x; cin >> x;
            if (x > big) good = 0;
            if (x == big){
                if (cnt) cnt--;
                else good = 0;
            }
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
}
