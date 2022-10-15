#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> idxs;
    string s;
    for (int i = 0; i < N; ++i){
        char c; cin >> c; s += c;
        if (c == '0') idxs.push_back(i);
    }
    int worst = 0, idx = 0;
    for (int i = 0; i < M; ++i){
        int x; cin >> x;
        if (x >= worst) worst = x, idx = idxs[i];
    }
    for (int i = 0; i < N; ++i){
        if (s[(idx + i) % N] != '0')
            cout << s[(idx + i) % N];
    }
    cout << '\n';
}
