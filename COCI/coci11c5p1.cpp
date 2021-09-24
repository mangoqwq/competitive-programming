#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 30;

char g[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string A, B; cin >> A >> B;
    int r, c;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < A.size(); ++j){
            g[i][j] = '.';
        }
    }
    for (int i = 0; i < A.size(); ++i){
        int idx = B.find(A[i]);
        if (idx != B.npos){
            r = idx;
            c = i;
            break;
        }
    }
    for (int i = 0; i < A.size(); ++i){
        g[r][i] = A[i];
    }
    for (int i = 0; i < B.size(); ++i){
        g[i][c] = B[i];
    }
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < A.size(); ++j){
            cout << g[i][j];
        }
        cout << '\n';
    }
}
