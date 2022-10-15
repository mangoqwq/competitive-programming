#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int N, L; cin >> N >> L;
    vector<int> t(N), p(N), d(N);
    for (int i = 0; i < N; ++i){
        cin >> p[i] >> d[i];
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return p[a] < p[b];
    });

    deque<int> r, l;
    for (int j = N - 1; j >= 0; --j){
        int i = ord[j];
        if (d[i] == 0) l.push_front(i);
    }
    for (int j = 0; j < N; ++j){
        int i = ord[j];
        if (d[i] == 0){
            l.pop_front();
        }
        int mn = min(r.size(), l.size());
        if (d[i] == 0){
            if (r.size() == 0) t[i] = p[i];
            else if (r.size() == l.size()) t[i] = p[l[mn - 1]];
            else if (r.size() > l.size()) t[i] = L - p[r[mn]];
            else if (r.size() < l.size()) t[i] = p[l[mn - 1]];
        }
        if (d[i] == 1){
            if (l.size() == 0) t[i] = L - p[i];
            else if (r.size() == l.size()) t[i] = L - p[r[mn - 1]];
            else if (r.size() > l.size()) t[i] = L - p[r[mn - 1]];
            else if (r.size() < l.size()) t[i] = p[l[mn]];
            r.push_front(i);
        }
    }

    sort(ord.begin(), ord.end(), [&](int a, int b){
        return tie(t[a], a) < tie(t[b], b);
    });
    for (int x : ord) cout << x + 1 << " ";
    cout << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
