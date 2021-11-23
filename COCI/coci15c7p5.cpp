#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 151, MM = 5e6 + 1e3;

bool prime[MM];
int a[MM], big[MN][MN];

int sum(int l, int r){
    if (r < l) return 0;
    return a[r] - a[l - 1];
}
void build(){
    ms(prime, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < MM; ++i){
        a[i] = prime[i] + a[i - 1];
        if (!prime[i]) continue;
        for (ll j = 1LL * i * i; j < MM; j += i){
            prime[j] = 0;
        }
    }
    int bad = -1;
    for (int i = 5e6; i >= 1; --i){
        if (i <= (int)(5e6 - 1e5) && !prime[i]) continue;
        for (int j = MN - 1; j >= 1; --j){
            int cnt = a[i + j - 1] - a[i - 1];
            if (cnt == 0){
                if (j > bad){
                    for (int k = j; k > bad; --k) big[0][k] = i;
                    bad = j;
                }
                break;
            }
            big[cnt][j] = max(big[cnt][j], i);
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    build();
    int Q; cin >> Q;
    while (Q--){
        int N, L, M; cin >> N >> L >> M;
        // cout << "-> " << big[L][N] << '\n';
        if (big[L][N] > M){
            cout << big[L][N] << '\n';
            continue;
        }
        int ans = -1;
        for (int i = 1; i <= M; ++i){
            if (M - i + 1 + sum(M + 1, i + N - 1) == L) ans = i;
        }
        cout << ans << '\n';
    }
}
