#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Item{ int i, l, r, c; };
int dp[55][55][55][4];
Item lst[55][55][55][4];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<vector<char>> g(N+1, vector<char>(M+1));
        vector<int> cnt(N+1);
        int LX = N, RX = 1, LY = M, RY = 1;
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= M; ++j){
                cin >> g[i][j];
                cnt[i] += g[i][j] == '#';
                if (g[i][j] == '#'){
                    LX = min(LX, i);
                    RX = max(RX, i);
                    LY = min(LY, j);
                    RY = max(RY, j);
                }
                for (int k = 0; k <= M+1; ++k){
                    dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = dp[i][j][k][3] = 1e9;
                }
            }
        }

        auto chmin = [&](int i, int l, int r, int c, int pi, int pl, int pr, int pc, int add){
            if (dp[i][l][r][c] > dp[pi][pl][pr][pc] + add){
                dp[i][l][r][c] = dp[pi][pl][pr][pc] + add;
                lst[i][l][r][c] = {pi, pl, pr, pc};
            }
        };

        for (int l = LY; l <= RY; ++l){
            for (int r = l; r <= RY; ++r){
                for (int c = 0; c < 4; ++c)
                    dp[LX-1][l][r][c] = 0;
            }
        }
        for (int i = LX; i <= RX; ++i){
            for (int l = LY; l <= RY; ++l){
                int cur = 0;
                for (int r = l; r <= RY; ++r){
                    cur += g[i][r] == '#';
                    if (cur != cnt[i]) continue;
                    int sz = r-l+1;

                    for (int pl = l; pl <= r; ++pl){
                        for (int pr = r; pr <= RY; ++pr){
                            chmin(i,l,r,0, i-1,pl,pr,0, sz);
                            chmin(i,l,r,0, i-1,pl,pr,2, sz);
                        }
                    }

                    for (int pr = r; pr >= l; --pr){
                        for (int pl = l; pl >= LY; --pl){
                            chmin(i,l,r,1, i-1,pl,pr,1, sz);
                            chmin(i,l,r,1, i-1,pl,pr,2, sz);
                        }
                    }

                    for (int pl = l; pl <= r; ++pl){
                        for (int pr = pl; pr <= r; ++pr){
                            chmin(i,l,r,2, i-1,pl,pr,2, sz);
                        }
                    }
                    
                    for (int pl = l; pl >= LY; --pl){
                        for (int pr = r; pr <= RY; ++pr){
                            chmin(i,l,r,3, i-1,pl,pr,0, sz);
                            chmin(i,l,r,3, i-1,pl,pr,1, sz);
                            chmin(i,l,r,3, i-1,pl,pr,2, sz);
                            chmin(i,l,r,3, i-1,pl,pr,3, sz);
                        }
                    }
                }
            }
        }

        int best = 1e9;
        Item cur;
        for (int l = 1; l <= M; ++l){
            for (int r = l; r <= M; ++r){
                for (int c = 0; c < 4; ++c){
                    if (dp[RX][l][r][c] < best){
                        best = dp[RX][l][r][c];
                        cur = {RX,l,r,c};
                    }
                }
            }
        }

        vector<vector<char>> ans(N+1, vector<char>(M+1, '.'));
        for (int i = RX; i >= LX; --i){
            for (int j = cur.l; j <= cur.r; ++j){
                ans[i][j] = '#';
            }
            cur = lst[cur.i][cur.l][cur.r][cur.c];
        }
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= M; ++j){
                cout << ans[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
        // cout << best << '\n';
    }
}

/*
#....
.....
....#

###.
.###
###.
*/
