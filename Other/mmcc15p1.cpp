#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5;

int p[MN], sz[MN], a[MN], b[MN], T;
int Find(int x){ return p[x] == x ? x : Find(p[x]); }

void Init(int N){
    iota(p, p + N, 0);
    fill(sz, sz + N, 1);
}

void AddEdge(int A, int B){
    A = Find(A - 1), B = Find(B - 1);
    if (A == B) A = -1, B = -1;
    else{
        if (sz[B] > sz[A]) swap(A, B);
        p[B] = A;
        sz[A] += sz[B];
    }
    a[++T] = A, b[T] = B;
}

void RemoveLastEdge(){
    int A = a[T], B = b[T--];
    if (A == -1) return;
    sz[A] -= sz[B];
    p[B] = B;
}

int GetSize(int A){ return sz[A - 1]; }

int main(){
    cin.tie(0)->sync_with_stdio(0);

}
