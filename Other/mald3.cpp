#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<ll> cats(N);
    for (int i = 0; i < N; ++i){
        cin >> cats[i];
    }
    sort(cats.begin(), cats.end());
    int d = 0, pl = 0, pr = N - 1, bad = 0;
    while (true){
        if (cats[pl] - 1 == d || bad >= K){
            d++;
            int groups = min(bad / K, pr + 1);
            pr -= groups, bad += groups;
            while (pl < N && cats[pl] == d) pl++, bad++;
        }
        else{
            d = cats[pl] - 1;
        }
        if (pl > pr){
            cout << d << '\n';
            break;
        }
    }
}
