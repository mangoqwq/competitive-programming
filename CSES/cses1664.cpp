#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int A = 1e6;
    const int L = __lg(A);

    int N, Q; cin >> N >> Q;
    vector<int> mn(A + 1, 1e9);
    for (int i = 1; i <= N; ++i){
        int l, r; cin >> l >> r;
        mn[l] = min(mn[l], r);
    }

    vector<vector<int>> st(A + 2, vector<int>(L + 1, 1e9));
    for (int i = A; i >= 0; --i){
        st[i][0] = min(st[i + 1][0], mn[i]);
    }
    for (int j = 1; j <= L; ++j){
        for (int i = 1; i + (1 << j) - 1 <= A; ++i){
            if (st[i][j - 1] == 1e9) st[i][j] = 1e9;
            else st[i][j] = st[st[i][j - 1]][j - 1];
        }
    }

    while (Q--){
        int l, r; cin >> l >> r;
        int cnt = 0;
        for (int j = L; j >= 0; --j){
            if (st[l][j] <= r){
                cnt += (1 << j);
                l = st[l][j];
            }
        }
        cout << cnt << '\n';
    }
}
