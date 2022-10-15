#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

string s;
int a[MN];

struct Fenwick{
    int a[MN + 10];
    void ins(int i, int v){ for (++i; i < MN; i += i & -i) a[i] += v; }
    int qry(int i){
        int ret = 0;
        for (++i; i; i -= i & -i) ret += a[i];
        return ret;
    }
    void reset(){ ms(a, 0); }
} bit;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int L, R; cin >> L >> R;
    cin >> s; int N = s.size(); s = " " + s;
    for (int i = 1; i <= N; ++i){
        if (s[i] == '1') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
    }
    ll ans1 = 0, ans2 = 0;
    vector<int> ord(N + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        int vi = 100 * a[i] - R * i;
        int vj = 100 * a[j] - R * j;
        if (vi == vj) return i < j;
        else return vi > vj;
    });
    for (int i : ord){
        ans1 += bit.qry(i);
        bit.ins(i, 1);
    }
    bit.reset();

    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        int vi = 100 * a[i] - L * i;
        int vj = 100 * a[j] - L * j;
        if (vi == vj) return i > j;
        else return vi > vj;
    });
    for (int i : ord){
        ans1 -= bit.qry(i);
        bit.ins(i, 1);
    }
    bit.reset();

    for (int i = 1; i <= N; ++i) a[i] *= -1;
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        int vi = 100 * a[i] - R * i;
        int vj = 100 * a[j] - R * j;
        if (vi == vj) return i < j;
        else return vi > vj;
    });
    for (int i : ord){
        ans2 += bit.qry(i);
        bit.ins(i, 1);
    }
    bit.reset();


    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        int vi = 100 * a[i] - L * i;
        int vj = 100 * a[j] - L * j;
        if (vi == vj) return i > j;
        else return vi > vj;
    });
    for (int i : ord){
        ans2 -= bit.qry(i);
        bit.ins(i, 1);
    }

    ll ans3 = 0;
    if (L == 0){
        map<int, int> cnt;
        for (int i = 0; i <= N; ++i){
            ans3 += cnt[a[i]];
            cnt[a[i]]++;
        }
    }
    cout << ans1 + ans2 - ans3 << '\n';
}
