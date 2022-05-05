#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll adj_diff(int H, int W, int R[500][500], int G[500][500], int B[500][500]){
    ll ret = 0;
    int lr = 0, lg = 0, lb = 0;
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            ll cur = abs(R[i][j] - lr) + abs(G[i][j] - lg) + abs(B[i][j] - lb);
            ret += cur;
            lr = R[i][j], lg = G[i][j], lb = B[i][j];
        }
    }
    return ret / H / W;
}

ll total_color(int H, int W, int R[500][500], int G[500][500], int B[500][500]){
    ll ret = 0;
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            ret += (R[i][j] + G[i][j] + B[i][j]) * (R[i][j] + G[i][j] + B[i][j]);
        }
    }
    return ret / H / W;
}

int style(int H, int W, int R[500][500], int G[500][500], int B[500][500]) {

    ll diff = adj_diff(H, W, R, G, B);
    ll color = total_color(H, W, R, G, B);

    if (diff <= 8) return 4;
    if (diff >= 54) return 3;
    if (color >= 150'000) return 1;
    return 2;
}

int getR(int RGB) { return (RGB >> 16) & 0xFF; }

int getG(int RGB) { return (RGB >> 8) & 0xFF; }

int getB(int RGB) { return RGB & 0xFF; }

int R[500][500], G[500][500], B[500][500];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int H, W; cin >> H >> W;
        for (int i = 0; i < H; ++i){
            for (int j = 0; j < W; ++j){
                int x; cin >> x;
                R[i][j] = getR(x);
                G[i][j] = getG(x);
                B[i][j] = getB(x);
            }
        }
        cout << style(H, W, R, G, B) << '\n';
    }
}

