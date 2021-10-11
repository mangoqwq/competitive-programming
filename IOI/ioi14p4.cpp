#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 9, inf = 0x3f3f3f3f;
const int MN = 0;

void find_valid(int n, int a[], int ans[]){
    int last = 0;
    for (int i = 0; i < n; ++i){
        if (last == 0){
            if (a[i] <= n) last = a[i];
        }
        else{
            if (++last == n + 1) last = 1;
        }
    }
    for (int i = 0; i < n; ++i){
        if (++last == n + 1) last = 1;
        ans[i] = last;
    }
}

vector<int> find_need(int n, int a[], int valid[]){
    vector<int> ret;
    for (int i = 0; i < n; ++i){
        if (a[i] <= n) continue;
        ret.push_back(i);
    }
    sort(ret.begin(), ret.end(), [a](int i, int j){ return a[i] < a[j]; });
    return ret;
}

int valid(int n, int a[]){
    set<int> s;
    int valid[n]; find_valid(n, a, valid);
    for (int i = 0; i < n; ++i){
        s.insert(a[i]);
        if (a[i] <= n && valid[i] != a[i]) return 0;
    }
    return s.size() == n;
}

int replacement(int n, int a[], int ans[]){
    int valid[n]; find_valid(n, a, valid);
    vector<int> need = find_need(n, a, valid);
    int l = 0;
    for (auto i : need){
        ans[l++] = valid[i];
        valid[i] = n + l;
        while (valid[i] != a[i]){
            l++;
            valid[i] = n + l;
            ans[l - 1] = valid[i] - 1;
        }
    }
    return l;
}

ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}

int countReplacement(int n, int a[]){
    if (!valid(n, a)) return 0;
    int valid[n]; find_valid(n, a, valid);
    vector<int> need = find_need(n, a, valid);
    if (need.empty()) return 1;
    ll ans = fpow(need.size(), (a[need[0]] - n - 1));
    for (int i = 1; i < need.size(); ++i){
        ans = ans * fpow(need.size() - i, a[need[i]] - a[need[i - 1]] - 1) % mod;
    }
    if (need.size() == n){
        ans = ans * n % mod;
    }
    return ans;
}
