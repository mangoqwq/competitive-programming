#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> build_sa(string s){
    int N = s.size(), classes;
    vector<int> sa(N), san(N), c(N), cn(N), cnt(max(128, N));
    for (int i = 0; i < N; ++i) cnt[s[i] - '$']++;
    for (int i = 1; i < 128; ++i) cnt[i] += cnt[i - 1];
    for (int i = N - 1; i >= 0; --i) sa[--cnt[s[i] - '$']] = i;
    c[sa[0]] = 0;
    classes = 1;
    for (int i = 1; i < N; ++i){
        if (s[sa[i]] != s[sa[i - 1]]) classes++;
        c[sa[i]] = classes - 1;
    }
    for (int b = 0; (1 << b) < N; ++b){
        for (int i = 0; i < N; ++i){
            san[i] = sa[i] - (1 << b);
            if (san[i] < 0) san[i] += N;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < N; ++i) cnt[c[san[i]]]++;
        for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
        for (int i = N - 1; i >= 0; --i) sa[--cnt[c[san[i]]]] = san[i];
        cn[sa[0]] = 0;
        classes = 1;
        for (int i = 1; i < N; ++i){
            if (tie(c[sa[i]], c[(sa[i] + (1 << b)) % N]) != tie(c[sa[i - 1]], c[(sa[i - 1] + (1 << b)) % N]))
                classes++;
            cn[sa[i]] = classes - 1;
        }
        swap(cn, c);
    }
    return sa;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vector<int> sa = build_sa(s + "$");
    sa.erase(sa.begin());

    int Q; cin >> Q;
    while (Q--){
        string t; cin >> t;
        int lo = 0, hi = N - 1;
        bool found = 0;
        while (lo <= hi){
            int mid = (lo + hi) >> 1;
            int dir = 0;
            for (int i = 0; i < t.size(); ++i){
                if (sa[mid] + i >= N){ dir = 1; break; }
                if (s[sa[mid] + i] < t[i]){ dir = 1; break; }
                if (s[sa[mid] + i] > t[i]){ dir = -1; break; }
            }
            if (dir == -1) hi = mid - 1;
            if (dir == 1) lo = mid + 1;
            if (dir == 0){ found = 1; break; }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
}
