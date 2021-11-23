#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e4 + 1;

ll N, a[MN];
ll ask(int i, int j){
    cout << "? " << i << " " << j << '\n';
    cout.flush();
    ll x; cin >> x;
    return x;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i < N; i += 2){
        ll xmy = ask(i, i + 1);
        ll y = ask(i, i + 1) / 2;
        a[i + 1] = y;
        a[i] = xmy + y;
    }
    if (N % 2 == 1){
        a[N] = - ask(N - 1, N) + 2 * a[N - 1];
    }

    cout << "! ";
    for (int i = 1; i <= N; ++i){
        cout << a[i] << (i != N ? ' ' : '\n');
    }
}
