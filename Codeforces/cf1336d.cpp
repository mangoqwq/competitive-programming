#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;

    // adding x gives (diff) more triplets, how many x are there now?
    // (ans-1 choose 2) = diff
    map<ll, int> mp;
    for (int i = 2; i <= 2*N; ++i){
        mp[(i-2) * (i-1) / 2] = i;
    }
    auto rev = [&](ll diff) -> int {
        return mp[diff];
    };

    struct State{ ll aaa, abc; };
    deque<State> q;
    vector<int> added(N+1);

    auto read = [&]() -> void {
        ll aaa, abc;
        cin >> aaa >> abc;
        q.push_front({aaa, abc});
    };
    auto guess = [&](int x) -> void {
        cout << "+ " << x << '\n';
        cout.flush();
        added[x]++;
        read();
    };

    vector<int> ans(N+1, -1);
    read();
    guess(3);
    guess(1);
    guess(2);
    guess(1);
    ans[1] = rev(q[0].aaa - q[1].aaa);
    ans[3] = (q[0].abc - q[1].abc) - (q[2].abc - q[3].abc);
    ans[2] = (q[0].abc - q[1].abc) / ans[3];
    ll tmp = ((q[1].abc - q[2].abc) - (ans[1]-1)*ans[3]) / ans[3];
    if (N == 4){
        ans[4] = tmp;
    }
    else{
        vector<int> zero(N+1);
        zero[4] = tmp == 0;
        for (int i = 4; i < N; ++i){
            guess(i);
            if (zero[i]) ans[i] = 1;
            else ans[i] = rev(q[0].aaa - q[1].aaa);
            if (q[0].abc - (ans[i-1] * ans[i-2]) == q[1].abc) zero[i+1] = 1;
        }
        ans[N] = ((q[0].abc - q[1].abc) - (ans[N-2] * ans[N-3])) / ans[N-2];
    }

    cout << "! ";
    for (int i = 1; i <= N; ++i){
        cout << ans[i] - added[i] << " ";
    }
    cout << '\n';
}
