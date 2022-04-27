#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'A']++;
    string ans;
    function<void(int, int)> dfs = [&](int idx, int lst){
        if (idx == 0){
            cout << ans << '\n';
            exit(0);
        }
        int a = 25, b = 25;
        for (int i = 25; i >= 0; --i){
            if (i == lst) continue;
            if (cnt[i]) a = i;
            if (cnt[i] >= cnt[b]) b = i;
        }
        if (cnt[b] > (idx + 1) / 2){    
            return;
        }

        ans += a + 'A';
        cnt[a]--;
        dfs(idx - 1, a);
        ans.pop_back();
        cnt[a]++;

        ans += b + 'A';
        cnt[b]--;
        dfs(idx - 1, b);
        ans.pop_back();
        cnt[b]++;
    };
    dfs(s.size(), -1);
    cout << -1 << '\n';
}
