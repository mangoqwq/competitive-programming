#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        map<char, int> cnt;
        map<char, vector<int>> poses;
        for (int i = 0; i < N; ++i){
            cnt[s[i]]++;
            poses[s[i]].push_back(i);
        }
        int ans = 1e9;
        string best = s;

        auto attempt = [&](int c){ // num occurances
            map<char, int> mp = cnt;
            using pii = pair<int, int>;
            vector<pii> vec;
            for (int i = 'a'; i <= 'z'; ++i){
                vec.push_back({mp[i], i});
            }
            sort(vec.begin(), vec.end(), greater<pii>());
            int l = N / c;
            map<char, int> nxt;
            for (int i = 0; i < l; ++i){
                nxt[vec[i].second] = c;
            }
            vector<int> vis(N);
            string ret(N, '.');
            for (int i = 0; i < N; ++i){
                if (nxt[s[i]]) vis[i] = 1, ret[i] = s[i], nxt[s[i]]--;
            }
            vector<char> left;
            for (auto [a, b] : nxt){
                for (int i = 0; i < b; ++i){
                    left.push_back(a);
                }
            }
            int cans = 0;
            for (int i = 0; i < N; ++i){
                if (vis[i]) continue;
                ret[i] = left.back();
                left.pop_back();
                cans++;
            }
            if (cans < ans){
                best = ret;
                ans = cans;
            }
        };

        for (int x = 1; x * x <= N; ++x){ // num occurances, num letters
            if (N % x) continue;
            if (N / x <= 26){
                attempt(x);
            }
            if (x <= 26){
                attempt(N/x);
            }
        }
        cout << ans << '\n';
        cout << best << '\n';
    }
}
