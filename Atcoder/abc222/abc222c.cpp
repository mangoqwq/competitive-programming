#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;

int id[MN], score[MN];
string play[MN];

int win(char a, char b){
    if (a == b) return -1;
    if (a == 'G' && b == 'C') return 0;
    if (a == 'C' && b == 'P') return 0;
    if (a == 'P' && b == 'G') return 0;
    return 1;
}

bool cmp(int a, int b){
    if (score[a] == score[b]) return a < b;
    return score[a] > score[b];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= 2 * n; ++i) id[i] = i;
    for (int i = 1; i <= 2 * n; ++i) cin >> play[i], play[i] = " " + play[i];
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            int result = win(play[id[2 * j]][i], play[id[2 * j - 1]][i]);
            if (result == 0) score[id[2 * j]]++;
            else if (result == 1) score[id[2 * j - 1]]++;
        }
        sort(id + 1, id + 1 + 2 *n, cmp);
    }
    for (int i = 1; i <= 2 * n; ++i) cout << id[i] << '\n';
}
