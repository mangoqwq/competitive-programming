#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 6e5 + 1;

struct Query{ char op; int a, b; };
struct Fenwick{
    int a[MN];
    void upd(int i, int v){
        for (; i < MN; i += i & -i) a[i] += v;
    }
    int qry(int i){
        int ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
    int qry(int l, int r){ return qry(r) - qry(l - 1); }
} bit;
int arr[MN];
vector<int> comp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<Query> qs;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        qs.push_back({'!', i, x});
        comp.push_back(x);
    }
    for (int i = 1; i <= Q; ++i){
        char c; cin >> c;
        if (c == '!'){
            int k, x; cin >> k >> x;
            comp.push_back(x);
            qs.push_back({c, k, x});
        }
        else{
            int l, r; cin >> l >> r;
            comp.push_back(l);
            comp.push_back(r);
            qs.push_back({c, l, r});
        }
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for (auto [op, a, b] : qs){
        if (op == '!'){
            b = lower_bound(comp.begin(), comp.end(), b) - comp.begin() + 1;
            if (arr[a]) bit.upd(arr[a], -1);
            arr[a] = b;
            bit.upd(arr[a], 1);
        }
        if (op == '?'){
            a = lower_bound(comp.begin(), comp.end(), a) - comp.begin() + 1;
            b = lower_bound(comp.begin(), comp.end(), b) - comp.begin() + 1;
            cout << bit.qry(a, b) << '\n';
        }
    }
}
