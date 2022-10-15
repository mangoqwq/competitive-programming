#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    set<int> cur, last;
    cur.insert(0);
    for (int i = 1; i <= N; ++i){
        swap(cur, last); cur = last;
        int a; cin >> a;
        for (int x : last) cur.insert(x + a);
    }
    cout << cur.size() << '\n';
}
