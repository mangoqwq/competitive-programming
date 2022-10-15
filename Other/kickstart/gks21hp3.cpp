#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 10;

int a[MN];
int lst[MN], nxt[MN];
set<int> q[10];

bool good(int i){
    return (a[i] + 1) % 10 == a[nxt[i]];
}

void solve(){
    int N; cin >> N;

    for (int i = 1; i <= N; ++i){
        lst[i] = i - 1;
        nxt[i] = i + 1;
    }
    a[0] = a[N + 1] = inf;


    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i < N; ++i){
        if (good(i)) q[a[i]].insert(i);
    }

    bool changed = 1;
    while (changed){
        changed = 0;
        for (int c = 0; c <= 9; ++c){
            for (int i : q[c]){
// cout << a[i] << " " << a[nxt[i]] << " " << i << " " << nxt[i] << '\n';
                a[i] = (a[i] + 2) % 10;
                int old = nxt[i];

                if (nxt[i] != N + 1){
                    lst[nxt[nxt[i]]] = i;
                    nxt[i] = nxt[nxt[i]];
                    if (good(i)) q[a[i]].insert(i);
                    else q[a[old]].erase(old);
                }

                if (lst[i] != 0){
                    nxt[lst[i]] = i; 
                    lst[i] = lst[i];
                    if (good(lst[i])) q[a[lst[i]]].insert(lst[i]);
                    else q[a[lst[i]]].erase(lst[i]);
                }

                a[old] = -1;
                changed = 1;
            }
            q[c].clear();
        }
    }
    for (int i = 1; i <= N; ++i){
        if (a[i] != -1) cout << a[i];
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
