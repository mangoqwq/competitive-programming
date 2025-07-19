#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
vector<int> build_sa(string s){
    int N = s.size();
    vector<int> sa(N), san(N), c(N), cn(N), cnt(max(128, N));
    for (int i = 0; i < N; ++i) cnt[s[i] - '$']++;
    for (int i = 1; i < 128; ++i) cnt[i] += cnt[i - 1];
    for (int i = 0; i < N; ++i) sa[--cnt[s[i] - '$']] = i;
    c[sa[0]] = 0;
    int classes = 1;
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
        swap(c, cn);
    }
    return sa;
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vector<int> sa = build_sa(s + "$");
    sa.erase(sa.begin());
 
    auto cmp1 = [&](const int &l, const string &t) -> bool{
        for (int i = 0; i < t.size(); ++i){
            if (l + i >= N) return 1;
            if (s[l + i] != t[i]) return s[l + i] < t[i];
        }
        return 0;
    };
    auto cmp2 = [&](const string &t, const int &l) -> bool{
        for (int i = 0; i < t.size(); ++i){
            if (l + i >= N) return 1;
            if (s[l + i] != t[i]) return 1;
        }
        return 0;
    };
 
    int Q; cin >> Q;
    while (Q--){
        string t; cin >> t;
        int l = lower_bound(sa.begin(), sa.end(), t, cmp1) - sa.begin();
        int r = upper_bound(sa.begin() + l, sa.end(), t, cmp2) - sa.begin();
        cout << r - l << '\n';
    }
}
