#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N), b(N);
    vector<int> row, col;
    for (int i = 0; i < N; ++i){
        cin >> a[i] >> b[i];
        row.push_back(a[i]);
        col.push_back(b[i]);
    }
    sort(row.begin(),row.end());
    sort(col.begin(),col.end());
    row.resize(unique(row.begin(), row.end()) - row.begin());
    col.resize(unique(col.begin(), col.end()) - col.begin());
    for (int i = 0; i < N; ++i){
        int ansa = lower_bound(row.begin(), row.end(), a[i]) - row.begin() + 1;
        int ansb = lower_bound(col.begin(), col.end(), b[i]) - col.begin() + 1;
        cout << ansa << " " << ansb << '\n';
    }
}
