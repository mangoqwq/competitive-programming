#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e3 + 1;
vector<int> a[MN];
int score[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, S; cin >> N >> S;
    for (int i = 1; i <= N / S; ++i){
        for (int j = 1; j <= S; ++j){
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 1; i <= (S - 1) * N / 2; ++i){
        int a, b; char c; cin >> a >> b >> c;
        if (c == 'W') score[a] += 3;
        if (c == 'L') score[b] += 3;
        if (c == 'T') score[a] += 1, score[b] += 1;
    }
    int K; cin >> K;
    for (int i = 1; i <= N / S; ++i){
        sort(a[i].begin(), a[i].end(), [](int a, int b){ return tie(score[a], b) > tie(score[b], a); });
        cout << a[i][K - 1] << (i == N / S ? '\n' : ' ');
    }
}
