#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2001;

bool adj[MAXN][MAXN];
int lst[MAXN], nxt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=2;i<=n;++i){
        for (int j=1;j<i;++j){
            char a; cin >> a;
            adj[i][j]=adj[j][i]=a=='B';
        }
    }
    for (int src=1;src<=n;++src){
        ms(lst,0), ms(nxt,0);
        int m=src, p=src;
        for (int i=1;i<=n;++i){
            if (i==src) continue;
            if (m==src||m==p){
                int a=p;
                lst[i]=a; nxt[a]=i;
                if (adj[i][a]==adj[lst[a]][a]) m=i;
                else m=a;
                p=i;
            }
            else{
                if (adj[i][m]==adj[m][lst[m]]){
                    int a=m, b=nxt[m];
                    if (adj[i][a]==adj[i][b]) m=b;
                    else m=i;
                    nxt[a]=i, lst[b]=i;
                    lst[i]=a, nxt[i]=b;
                }
                else{
                    int a=lst[m], b=m;
                    if (adj[i][a]==adj[i][b]) m=a;
                    else m=i;
                    nxt[a]=i, lst[b]=i;
                    lst[i]=a, nxt[i]=b;
                }
            }
        }
        cout << n << '\n';
        for (int i=src;i;i=nxt[i]){
            cout << i << " ";
        }
        cout << '\n';
    }
}