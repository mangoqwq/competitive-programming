#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        int cur = 1;
        for (int i = 0; i < N; ++i){
            int x; cin >> x;
            if (x == cur) cur++;
        }
        cout << ((N-cur+1) + K-1) / K << '\n';
    }
}
