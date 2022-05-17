#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> solve(int N, vector<int> a){

    if (N == 4) return vector<int>(N);

    auto mov = [&](int i, int shift){
        return (i + shift + N) % N;
    };

    vector<int> ans(N);
    for (int i = 0; i < N; ++i){
        if (a[mov(i, -1)] == a[mov(i, 1)]){
            ans[i] = a[mov(i, -1)];
        }
        if (a[mov(i, -1)] <= a[mov(i, 1)] && a[mov(i, 1)] < a[mov(i, 3)]){
            ans[i] = a[mov(i, 1)];
        }
        if (a[mov(i, 1)] <= a[mov(i, -1)] && a[mov(i, -1)] < a[mov(i, -3)]){
            ans[i] = a[mov(i, -1)];
        }
    }

    using pii = pair<int, int>;
    vector<pii> have;
    vector<int> need;
    vector<int> vis(N);
    for (int i = 0; i < N; ++i){
        if (!ans[i]){
            have.push_back({max(a[mov(i, -1)], a[mov(i, 1)]), i});
        }
        else{
            vis[ans[i] - 1] = 1;
        }
    }
    for (int i = 0; i < N; ++i){
        if (!vis[i]) need.push_back(i + 1);
    }

    sort(have.begin(), have.end());
    sort(need.begin(), need.end());
    int M = have.size(), r = 0;
    for (int i = 0; i < M; ++i){
        int cnt = 0;
        while (r < M && have[r].first <= need[i]){
            r++;
            cnt++;
        }
        if (r == i + 1 && cnt == 1){
            ans[have[i].second] = need[i];
        }
    }

    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) cin >> a[i];
        for (int x : solve(N, a)) cout << x << " ";
        cout << '\n';
    }
}
