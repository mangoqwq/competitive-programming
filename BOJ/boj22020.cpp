#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001, MAXA=257;

int g[MAXN][MAXN], mnx[MAXA], mxx[MAXA], mny[MAXA], mxy[MAXA];
int x1[MAXA], x2[MAXA];
int ins[MAXN], rem[MAXN];

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int n, m, s; cin >> n >> m >> s;
    ms(mnx,0x3f), ms(mny,0x3f);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            int c; cin >> c;
            g[i][j]=c;
            mnx[c]=min(mnx[c],i);
            mxx[c]=max(mxx[c],i);
            mny[c]=min(mny[c],j);
            mxy[c]=max(mxy[c],j);
        }
    }
    int t=0;
    for (int i=1;i<=256;++i){
        if (mnx[i]==inf) continue;
        t++;
        tie(x1[t],x2[t])=tie(mnx[i],mxx[i]);
    }
    sort(x1+1,x1+1+t), sort(x2+1,x2+1+t);
    int ans=t;
    for (int i=1;i<=t;++i){
        for (int j=1;j<=t;++j){
            int lx=x1[i], rx=x2[j];
            if (lx>rx) continue;
            ms(ins,0), ms(rem,0);
            int w=s/(rx-lx+1);
            for (int k=1;k<=256;++k){
                int ly=mny[k], ry=mxy[k];
                if (ry-ly+1>w||ry==0) continue;
                if (mnx[k]>=lx&&mxx[k]<=rx){
                    ins[ry]++; rem[ly]++;
                }
            }
            int l=1, curr=0;
            for (int r=1;r<=m;++r){
                while (l<=r-w) curr-=rem[l++];
                curr+=ins[r];
                ans=min(ans,t-curr);
            }
        }
    }
    cout << ans << '\n';
}