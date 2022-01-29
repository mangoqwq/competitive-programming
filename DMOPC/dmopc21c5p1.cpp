#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    if (N == 2 || N == 3 || N == 4){
        cout << -1 << '\n';
        return 0;
    }
    else if (N == 1){
        cout << 1 << '\n';
    }
    else{
        vector<int> ans(N + 1);
        int cur = 1;
        int p = 1;
        for (; cur <= N; ++p){
            ans[p] = cur;
            cur += 2;
        }
        p--;
        swap(ans[3], ans[p]);
        cur = 2;
        p++;
        int tmp = p;
        for (; cur <= N; ++p){
            ans[p] = cur;
            cur += 2;
        }
        swap(ans[tmp], ans[tmp + 1]);
        for (int i = 1; i <= N; ++i) cout << ans[i] << (i == N ? '\n' : ' ');
    }
}
