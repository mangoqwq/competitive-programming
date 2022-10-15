#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N + 1);
    vector<set<int>> s(10);
    function<void(int, int)> ins = [&](int a, int i){
        for (int b = 0; (1 << b) <= a; ++b){
            if (1 & (a >> b)){
                s[b].insert(i);
            }
        }
    };
    function<void(int, int)> del = [&](int a, int i){
        for (int b = 0; (1 << b) <= a; ++b){
            if (1 & (a >> b)){
                s[b].erase(i);
            }
        }
    };
    int sum = 0;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        ins(a[i], i);
        sum ^= a[i];
    }
    bool go = 0;
    if (sum == 0){
        cout << 1 << " " << 0 << '\n';
        cout.flush();
        go = 1;
    }
    while (true){
        if (go){
            int p, x; cin >> p >> x;
            if (p == 0 && x == 0) break;
            sum ^= a[p];
            del(a[p], p);
            a[p] -= x;
            sum ^= a[p];
            ins(a[p], p);
        }
        go = 1;

        int d = __lg(sum);
        int i = *s[d].begin();
        int rem = a[i] - (sum ^ a[i]);
        cout << i << " " << rem << '\n';
        cout.flush();
        del(a[i], i);
        a[i] -= rem;
        ins(a[i], i);
        sum = 0;
    }
}
