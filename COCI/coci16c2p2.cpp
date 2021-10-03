#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m, k, x; cin >> n >> m >> k >> x;
    string s; cin >> s;
    ll pos = 1, bad = 0;
    for (int i = 1; i <= m; ++i){
        if (pos > x) bad++;
        else pos = pos * k;
    }
    queue<char> q;
    for (int i = 1; i <= m; ++i){
        string cur; cin >> cur;
        sort(cur.begin(), cur.end());
        if (bad){
            bad--;
            q.push(cur[0]);
            continue;
        }
        pos /= k;
        for (char c : cur){
            if (x <= pos){
                q.push(c);
                break;
            }
            x -= pos;
        }
    }
    for (char c : s){
        if (c == '#') cout << q.front(), q.pop();
        else cout << c;
    }
    cout << '\n';
}
