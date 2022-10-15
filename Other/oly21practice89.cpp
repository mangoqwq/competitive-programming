#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
// const int MN = 50, SZ = 4, BLKS = MN / SZ + 5;
const int MN = 5e4 + 10, SZ = 150, BLKS = MN / SZ + 5;

ll psa[BLKS][BLKS];
vector<int> pos[MN];
int bcnt[BLKS][MN];
int a[MN], blk[MN], blkl[MN], blkr[MN];

int count(int l, int r, int x){
    return upper_bound(pos[x].begin(), pos[x].end(), r) -
           lower_bound(pos[x].begin(), pos[x].end(), l);
}
int nxtblk(int i){ return blkl[i] == i ? blk[i] : blk[i] + 1; }
int lstblk(int i){ return (i + 1) % SZ == 0 ? blk[i] : blk[i] - 1; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i <= N; ++i){
        blk[i] = i / SZ;
        bcnt[blk[i]][a[i]]++;
        if (i % SZ == 0) blkl[i] = i;
        else blkl[i] = blkl[i - 1];
    }
    for (int i = N; i >= 1; --i){
        if ((i + 1) % SZ == 0) blkr[i] = i;
        else blkr[i] = blkr[i + 1];
    }
    for (int l = 1; (l + 1) * SZ - 1 <= N; ++l){
        for (int r = 1; (r + 1) * SZ - 1 <= N; ++r){
            for (int i = l * SZ; blk[i] == l; ++i){
                psa[l][r] += bcnt[r][a[i]];
            }
            psa[l][r] += psa[l][r - 1];
        }
    }
    int Q; cin >> Q;
    while (Q--){
        ll ans = 0;
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        int bl = nxtblk(l2), br = lstblk(r2);
        for (int i = l1; i <= r1;){
            if (blkl[i] == i && i + SZ - 1 <= r1){
                if (bl <= br) ans += psa[blk[i]][br] - psa[blk[i]][bl - 1];
                i += SZ;
            }
            else{
                ans += count(l2, r2, a[i]);
                i++;
            }
        }
        int idxl = nxtblk(l1) * SZ, idxr = (lstblk(r1) + 1) * SZ - 1;
        if (idxl < idxr){
            for (int i = l2; i <= r2;){
                if (blkl[i] == i && i + SZ - 1 <= r2) i += SZ;
                else{
                    ans += count(idxl, idxr, a[i]);
                    i++;
                }
            }
        }
        cout << ans << '\n';
    }
}
