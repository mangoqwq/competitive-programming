#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3001;

int h[MN][MN], a[MN][MN], b[MN][MN];
deque<int> mn, mx;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int H, W, N; cin >> H >> W >> N;
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            cin >> h[i][j];
            while (!mn.empty() && mn.front() <= j - N) mn.pop_front();
            while (!mn.empty() && h[i][mn.back()] >= h[i][j]) mn.pop_back();
            while (!mx.empty() && mx.front() <= j - N) mx.pop_front();
            while (!mx.empty() && h[i][mx.back()] <= h[i][j]) mx.pop_back();
            mn.push_back(j); a[i][j] = h[i][mn.front()];
            mx.push_back(j); b[i][j] = h[i][mx.front()];
        }
        mn.clear(); mx.clear();
    }
    int ans = inf;
    for (int j = 1; j <= W; ++j){
        for (int i = 1; i <= H; ++i){
            while (!mn.empty() && mn.front() <= i - N) mn.pop_front();
            while (!mn.empty() && a[mn.back()][j] >= a[i][j]) mn.pop_back();
            while (!mx.empty() && mx.front() <= i - N) mx.pop_front();
            while (!mx.empty() && b[mx.back()][j] <= b[i][j]) mx.pop_back();
            mn.push_back(i);
            mx.push_back(i);
            if (i >= N && j >= N) ans = min(ans, b[mx.front()][j] - a[mn.front()][j]);
        }
        mn.clear(); mx.clear();
    }
    cout << ans << '\n';
}
