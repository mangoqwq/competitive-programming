#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    vector<vector<int>> trie(N * 30 + 1, vector<int>(2, 0));
    int T = 0;
    function<void(int)> ins = [&](int val){
        int v = 0;
        for (int i = 29; i >= 0; --i){
            int b = 1 & (val >> i);
            if (!trie[v][b]) trie[v][b] = ++T;
            v = trie[v][b];
        }
    };
    ins(0);
    int ans = 0;
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        if (i) a[i] ^= a[i - 1];
        int v = 0, val = 0;
        for (int j = 29; j >= 0; --j){
            int b = 1 & (a[i] >> j);
            int nb;
            if (trie[v][b ^ 1]) nb = b ^ 1;
            else nb = b;
            val += nb * (1 << j);
            v = trie[v][nb];
        }
        ans = max(ans, val ^ a[i]);
        ins(a[i]);
    }
    cout << ans << '\n';
}
