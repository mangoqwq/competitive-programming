#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 1;

set<int> can;
multiset<int> bad;
int l[MN], r[MN], ans[MN], T;
vector<int> vl[MN], vr[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= Q; ++i){
        int ql, qr; cin >> ql >> qr;
        vl[ql].push_back(i);
        vr[qr].push_back(i);
        l[i] = ql; r[i] = qr;
    }
    int pl = 1;
    for (int i = 1; i <= N; ++i){
        if (can.empty()) can.insert(++T);
        if (can.count(ans[i - 1])) ans[i] = ans[i - 1];
        else ans[i] = *can.begin();
        can.erase(ans[i]);
        for (int x : vl[i]){
            bad.insert(l[x]);
        }
        for (int x : vr[i]){
            bad.erase(bad.find(l[x]));
        }
        while (pl <= i && (bad.empty() || *bad.begin() > pl)){
            can.insert(ans[pl++]);
        }
    }
    cout << T << '\n';
    for (int i = 1; i <= N; ++i){
        cout << ans[i] << (i == N ? '\n' : ' ');
    }
}
