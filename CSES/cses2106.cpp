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
 
vector<int> lcp_array(const string &s, const vector<int> &sa){
    int N = s.size();
    vector<int> rank(N), lcp(N - 1);
    for (int i = 0; i < N; ++i) rank[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < N; ++i){
        if (rank[i] == N - 1){
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (max(i, j) + k < N && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vector<int> sa = build_sa(s + '$');
    sa.erase(sa.begin());
    vector<int> lcp = lcp_array(s, sa);
 
    int idx = max_element(lcp.begin(), lcp.end()) - lcp.begin();
    if (lcp[idx] == 0){
        cout << -1 << '\n';
    }
    else{
        cout << s.substr(sa[idx], lcp[idx]) << '\n';
    }
}
