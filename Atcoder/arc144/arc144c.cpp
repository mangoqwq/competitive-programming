#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    if (K * 2 > N){
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans(N + 1);
    int p = 1;
    while (p <= N){
        if (N - p + 1 >= 4 * K){
            for (int i = 0; i < K; ++i){
                ans[p + i] = p + i + K;
            }
            for (int i = K; i < 2*K; ++i){
                ans[p + i] = p + i - K;
            }
            p += 2 * K;
        }
        else{
            int tmp = p;
            for (int i = p; i <= N; ++i){
                if (i + K <= N) ans[i] = i + K;
                else ans[i] = tmp++;
            }
            if (N - p + 1 > 3*K){
                int cnt = N - p + 1 - 3*K;
                for (int i = 0; i < cnt; ++i){
                    swap(ans[p + K + i], ans[N - K + 1 + i]);
                }
                rotate(ans.begin() + N - K + 1, ans.begin() + N - K + 1 + cnt, ans.begin() + N + 1);
                // for (int i = N - K + 2; i <= N; ++i){
                //     swap(ans[i], ans[i - 1]);
                // }
            }
            p = N + 1;
        }
    }
    for (int i = 1; i <= N; ++i){
        cout << ans[i] << " ";
    }
    cout << '\n';
}
