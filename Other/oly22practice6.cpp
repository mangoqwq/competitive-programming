#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e4 + 1;

int N, M, K, X; 
int h[MN], s[MN], pot[MN];
int in[MN];
struct Item{
    int pot, i;
    bool operator<(const Item &other) const{
        return pot < other.pot; 
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K >> X;
    for (int i = 1; i <= N; ++i) cin >> h[i] >> s[i], pot[i] = h[i] + s[i] * M;
    priority_queue<Item> pq;
    for (int i = 1; i <= M; ++i){
        for (int i = 1; i <= N; ++i){
            h[i] += s[i];
            if (h[i] >= X && !in[i]) pq.push({pot[i], i}), in[i] = 1;
        }
        for (int i = 1; i <= K; ++i){
            if (pq.empty()) break;
            auto [_, v] = pq.top(); pq.pop();
            h[v] -= X; pot[v] -= X;
            if (h[v] >= X) pq.push({pot[v], v});
            else in[v] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        ans = max(ans, pot[i]);
    }
    cout << ans << '\n';
}
