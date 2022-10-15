#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    string s; cin >> s;
    for (int i = 1; i < N; ++i){
        if (N % i) continue;
        vector<int> tot(i);
        vector<vector<int>> cnt(i, vector<int>(26));
        for (int j = 0; j < N; ++j){
            tot[j % i]++;
            cnt[j % i][s[j] - 'a']++;
        }
        int cur = 0;
        for (int j = 0; j < i; ++j){
            cur += tot[j] - *max_element(cnt[j].begin(), cnt[j].end());
        }
        if (cur <= K){
            cout << i << '\n';
            return 0;
        }
    }
    cout << N << '\n';
}
