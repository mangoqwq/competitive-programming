#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int l[MN], r[MN], ord[MN];
bool ansl[MN], ansr[MN];
struct Fenwick{
    int a[2 * MN];
    void upd(int i){ for (; i < 2 * MN; i += i & -i) a[i]++; }
    int qry(int i){
        int ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
} bit;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> comp;
    for (int i = 1; i <= N; ++i){
        cin >> l[i] >> r[i];
        comp.push_back(l[i]);
        comp.push_back(r[i]);
        ord[i] = i;
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for (int i = 1; i <= N; ++i){
        l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin() + 1;
        r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin() + 1;
    }
    sort(ord + 1, ord + 1 + N, [](int a, int b){ return tie(l[a], r[b]) < tie(l[b], r[a]); });
    for (int i = 1; i <= N; ++i){
        int v = ord[i];
        ansl[v] =  i - bit.qry(r[v] - 1) - 1;
        bit.upd(r[v]);
    }
    ms(bit.a, 0);
    for (int i = N; i >= 1; --i){
        int v = ord[i];
        ansr[v] = bit.qry(r[v]);
        bit.upd(r[v]);
    }
    for (int i = 1; i <= N; ++i) cout << ansr[i] << " ";
    cout << '\n';
    for (int i = 1; i <= N; ++i) cout << ansl[i] << " ";
    cout << '\n';
}
