#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1;

int p[MN];
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) p[b] = 0;
    else p[b] = a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, L; cin >> N >> L;
    iota(p, p + 1 + L, 0);
    for (int i = 1; i <= N; ++i){
        int a, b; cin >> a >> b;
        if (Find(a) == a){
            Union(b, a);
        }
        else if (Find(b) == b){
            Union(a, b);
        }
        else if (Find(a) != 0){
            int rt = Find(a);
            p[rt] = p[a] = a;
            Union(b, a);
        }
        else if (Find(b) != 0){
            int rt = Find(b);
            p[rt] = p[b] = b;
            Union(a, b);
        }
        else{
            cout << "SMECE" << '\n';
            continue;
        }
        cout << "LADICA" << '\n';
    }
}
