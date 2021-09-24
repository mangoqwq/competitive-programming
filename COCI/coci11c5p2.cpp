#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> a(N);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    a.push_back(0);
    ll cut = 0;
    for (int i = 1; i <= N; ++i){
        ll need = min((M - cut + i - 1) / i, 0LL + a[i - 1] - a[i]);
        cut += need * i;
        if (cut >= M){
            cout << a[i - 1] - need << '\n';
            return 0;
        }
    }
}
