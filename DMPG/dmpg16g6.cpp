#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = (1 << 18), inf = 0x3f3f3f3f;
const int MN = (1 << 18) + 10, SZ = 500, BLKS = MN / SZ + 5;

int psa[BLKS][BLKS];
int cnt[BLKS][MN];
int bcnt[MN];
int a[MN], blk[MN], blkl[MN], blkr[MN];
ll cache[MN];

int nxtblk(int i){ return blkl[i] == i ? blk[i] : blk[i] + 1; }
int lstblk(int i){ return blkr[i] == i ? blk[i] : blk[i] - 1; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= N; ++i){
        blk[i] = i / SZ;
        if (i % SZ == 0) blkl[i] = i;
        else blkl[i] = blkl[i - 1];
    }
    for (int i = N; i >= 1; --i){
        blkr[i] = (i / SZ) * SZ + SZ - 1;
    }
    for (int l = 1; (l + 1) * SZ - 1 <= N; ++l){
        for (int i = l * SZ; blk[i] == l; ++i) bcnt[a[i]]++;
        for (int r = l; (r + 1) * SZ - 1 <= N; ++r){
            for (int i = r * SZ; blk[i] == r; ++i){
                psa[l][r] += bcnt[a[i]];
            }
            psa[r][l] = psa[l][r];
        }
        for (int i = 1; i <= N; ++i){
            cnt[l][i] = bcnt[a[i]];
        }
        for (int i = l * SZ; blk[i] == l; ++i) bcnt[a[i]]--;
    }
    for (int l = 1; (l + 1) * SZ - 1 <= N; ++l){
        for (int r = 1; (r + 1) * SZ - 1 <= N; ++r){
            psa[l][r] += psa[l][r - 1] + psa[l - 1][r] - psa[l - 1][r - 1];
        }
        for (int i = 1; i <= N; ++i) cnt[l][i] += cnt[l][i - 1] + cnt[l - 1][i] - cnt[l - 1][i - 1];
    }
    ll lastans = 0;
    while (Q--){
        ll ans = 0;
        int l, r; cin >> l >> r;
        l ^= lastans; l++;
        r ^= lastans; r++;
        int bl = nxtblk(l), br = lstblk(r);
        int idxl = nxtblk(l) * SZ - 1, idxr = (lstblk(r) + 1) * SZ;
        if (bl <= br){
            ans += psa[br][br] - psa[br][bl - 1] - psa[bl - 1][br] + psa[bl - 1][bl - 1];
            ans += 2 * (cnt[br][idxl] - cnt[br][l - 1] - cnt[bl - 1][idxl] + cnt[bl - 1][l - 1]);
            ans += 2 * (cnt[br][r] - cnt[br][idxr - 1] - cnt[bl - 1][r] + cnt[bl - 1][idxr - 1]);
        }
        for (int i = l; i <= r;){
            if (blkl[i] == i && i + SZ - 1 <= r) i += SZ;
            else{
                bcnt[a[i]]++;
                i++;
            }
        }
        for (int i = l; i <= r;){
            if (blkl[i] == i && i + SZ - 1 <= r) i += SZ;
            else{
                ans += bcnt[a[i]] * bcnt[a[i]];
                bcnt[a[i]] = 0;
                i++;
            }
        }
        cout << (lastans = ans & (mod - 1)) << '\n';
    }
}
