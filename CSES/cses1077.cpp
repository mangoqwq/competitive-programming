#include <bits/stdc++.h>
 
using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
int N, K, a[MN];
map<int, int> l, r;
ll sl, sr, lsz, rsz;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    l[0]++; lsz++;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        r[a[i]]++; sr += a[i]; rsz++;
        if (lsz > 0){
            int v = (--l.end())->first;
            l[v]--; sl -= v; lsz--;
            if (l[v] == 0) l.erase(v);
            r[v]++; sr += v; rsz++;
        }
        if (i >= K){
            int v = a[i - K];
            if (l.count(v)) l[v]--, sl -= v, lsz--;
            else r[v]--, sr -= v, rsz--;
            if (l[v] == 0) l.erase(v);
            if (r[v] == 0) r.erase(v);
        }
        while (rsz > lsz){
            int v = r.begin()->first;
            r[v]--; sr -= v, rsz--;
            if (r[v] == 0) r.erase(v);
            l[v]++; sl += v, lsz++;
        }
        while (lsz > rsz + 1){
            int v = (--l.end())->first;
            l[v]--; sl -= v, lsz--;
            if (l[v] == 0) l.erase(v);
            r[v]++; sr += v, rsz++;
        }
        if (i >= K){
            cout << (K % 2) * (--l.end())->first + (sr - sl) << " ";
        }
    }
    cout << '\n';
}
