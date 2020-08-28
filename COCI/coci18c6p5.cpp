#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
#define af(x) x.begin(), x.end()
#define pb push_back
const int mod = 1e9 + 7;
int r, c, n, m, sq, cur, g[305][305], dp[2][305][2005], idx[1000005]; vector<int> v;
void add(int &a, int b){a += b;if (a > mod) a -= mod;}
int main(){
    r = re, c = re, n = re - 1, sq = sqrt(n); v.pb(0) ;
    for (int i = 1; i <= n; i++) v.pb(n / i);
    sort(af(v)); v.resize(unique(af(v)) - v.begin()); m = (int)v.size();
    for (int i = 0; i < m; i++) idx[v[i]] = i;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            g[i][j] = re;
    dp[0][0][idx[n / g[0][0]]] = 1;
    for (int i = 0; i < r; i++, cur ^= 1){
        ms(dp[cur ^ 1], 0);
        for (int j = 0; j < c; j++){
            for (int x : v){
                if (!dp[cur][j][idx[x]]) continue;
                if (j != c - 1) add(dp[cur][j + 1][idx[x / g[i][j + 1]]], dp[cur][j][idx[x]]);
                if (i != r - 1) add(dp[cur ^ 1][j][idx[x / g[i + 1][j]]], dp[cur][j][idx[x]]);
            }
        }
    }
    printf("%d", dp[cur ^ 1][c - 1][0]);
}