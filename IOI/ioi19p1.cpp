#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

struct Fenwick{
    int a[MN];
    void ins(int i, int val){ for (++i; i < MN; i += i & -i) a[i] += val; }
    int qry(int i){
        int ret = 0;
        for (++i; i; i -= i & -i) ret += a[i];
        return ret;
    }
    int qry(int l, int r){ return qry(r) - qry(l); }
} bit;

map<int, queue<int>> mp;
ll count_swaps(vector<int> S){
    int N = S.size();
    ll ans = 0;
    for (int i = 0; i < N; ++i){
        if (!mp[-S[i]].empty()){
            if (S[i] < 0) ans++;
            int j = mp[-S[i]].front(); mp[-S[i]].pop();
            ans += bit.qry(j, i);
            bit.ins(j, 1);
        }
        else mp[S[i]].push(i), bit.ins(i, 1);
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> S = {2, 1, -1, -2};
    cout << count_swaps(S) << '\n';
}
