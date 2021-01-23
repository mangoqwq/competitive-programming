#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e4+2;

int l[MAXN], r[MAXN], vl[MAXN], vr[MAXN];

void go(int i, int pos, int c){
    if (r[i]<=pos){
        vl[i]=min(vl[i],c+pos-l[i]);
        vr[i]=min(vr[i],c+pos-l[i]+r[i]-l[i]);
    }
    else if (l[i]>=pos){
        vl[i]=min(vl[i],c+r[i]-pos+r[i]-l[i]);
        vr[i]=min(vr[i],c+r[i]-pos);
    }
    else{
        vl[i]=min(vl[i],c+r[i]-l[i]+r[i]-pos);
        vr[i]=min(vr[i],c+r[i]-l[i]+pos-l[i]);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    l[0]=1, r[0]=1;
    ms(vl,0x3f), ms(vr,0x3f);
    vl[0]=0, vr[0]=0;
    for (int i=1;i<=n;++i){
        cin >> l[i] >> r[i];
        go(i,l[i-1],vl[i-1]);
        go(i,r[i-1],vr[i-1]);
    }
    l[n+1]=n, r[n+1]=n;
    go(n+1,l[n],vl[n]);
    go(n+1,r[n],vr[n]);
    cout << vr[n+1]+n-1 << '\n';
}