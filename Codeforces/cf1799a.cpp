#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<int> ans(N, -1);
        set<int> s;
        int p = N - 1;
        for (int i = 0; i < M; ++i){
            int x; cin >> x;
            if (!s.count(x)){
                if (p >= 0){
                    ans[p] = i+1;
                    p--;
                }
            }
            s.insert(x);
        }
        for (int i = 0; i < N; ++i){
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}
