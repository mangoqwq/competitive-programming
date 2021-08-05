#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 5, MK = 2e6 + 5;

int N, M, psa[MN], pos[MK];

bool locate(int &i, int k){
    if (k < 0 || k > 2 * N) return 0;
    return i = pos[k];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    int lo= 0 , hi = 0;
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        if (c == 'T') psa[i] = psa[i - 1] + 2;
        else{
            psa[i] = psa[i - 1] + 1;
            if (!lo) lo = i;
            hi = i;
        }
        pos[psa[i]] = i;
    }
    while (M--){
        int i, k; cin >> k;
        if (locate(i, k)) cout << 1 << " " << i << '\n';
        else if (!lo) cout << "NIE" << '\n';
        else if (locate(i, k + psa[lo - 1])) cout << lo << " " << i << '\n';
        else if (locate(i, k + psa[lo])) cout << lo + 1 << " " << i << '\n';
        else if (locate(i, psa[hi] - k)) cout << i + 1 << " " << hi << '\n';
        else if (locate(i, psa[hi - 1] - k)) cout << i + 1 << " " << hi - 1 << '\n';
        else cout << "NIE" << '\n';
    }
}
