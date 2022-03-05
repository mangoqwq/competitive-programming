#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

#ifndef ONLINE_JUDGE
void allocate_tickets(vector<vector<int>> s){
    for (int i = 0; i < s.size(); ++i){
        for (int j = 0; j < s[i].size(); ++j){
            cout << s[i][j] << " ";
        }
        cout << '\n';
    }
}
#endif 

ll find_maximum(int K, vector<vector<int>> x){
    int N = x.size(), M = x[0].size();
    vector<int> idx(N);
    vector<vector<int>> s = vector<vector<int>>(N, vector<int>(M, -1));
    vector<int> left = vector<int>(K, N / 2); int low = 0;
    vector<vector<int>> seen = vector<vector<int>>(N, vector<int>(K, 0));
    ll ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < N; ++i){
        pq.push({x[i][M - K] + x[i][0], i});
        for (int j = M - K; j < M; ++j){
            ans += x[i][j];
        }
    }
    for (int k = 0; k < K * N / 2; ++k){
        auto [red, i] = pq.top(); pq.pop();
        ans -= red;
        idx[i]++;
        if (idx[i] != K){
            pq.push({x[i][idx[i]] + x[i][M - K + idx[i]], i});
        }
    }
    priority_queue<pii> ord;
    for (int i = 0; i < N; ++i){
        ord.push({idx[i], i});
    }
    for (int k = 0; k < K * N / 2; ++k){
        while (left[low] == 0) low++;
        auto [v, i] = ord.top(); ord.pop();
        int j = idx[i] - v;
        int val = (j == 0 ? low : max(low, s[i][j - 1] + 1));
        s[i][j] = val; left[val]--; seen[i][val] = 1;
        ord.push({v - 1, i});
    }
    for (int i = 0; i < N; ++i){
        int p = 0;
        for (int j = M - 1; j >= M - K + idx[i]; --j){
            while (p != K && seen[i][p]) p++;
            s[i][j] = p; p++;
        }
    }
    allocate_tickets(s);
    return ans;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int k = 4;
    vector<vector<int>> x = {{1, 5, 6, 7}, {3, 4, 5, 10}, {2, 2, 2, 3}, {0, 0, 15, 15}};
    cout << find_maximum(k, x) << '\n';
}
