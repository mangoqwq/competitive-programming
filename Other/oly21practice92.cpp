#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

string N; int K;
vector<int> state;

void dfs(int idx, bool low, bool zero, ll cur){
    if (idx == N.size()){
        cout << cur << '\n';
        exit(0);
    }
    int l = (low ? N[idx] : 0);
    for (int i = l; i <= 9; ++i){
        if (state[i] == K) continue;
        bool nzero = zero & (i == 0);
        if (!nzero) state[i]++;
        dfs(idx + 1, low & (i == l), nzero, cur * 10 + i);
        if (!nzero) state[i]--;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K; N = ('0' + N);
    for (char &c : N) c -= '0';
    state = vector<int>(10, 0);
    dfs(0, 1, 1, 0);
    cout << -1 << '\n';
}
