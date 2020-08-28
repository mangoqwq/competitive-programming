#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=701;

struct Dsu{int x,y,sz;};
struct Line{
    int m,b; 
    double sect(Line a){
        if (m==a.m&&a.b!=b) return -1;
        return (double)(a.b-b)/(double)(m-a.m);
    }
    bool operator==(const Line &a) const{return a.m==m&&a.b==b;}
};
map<ll,Dsu> p[MAXN+1][MAXN+1];
Line arr[MAXN+1][MAXN+1];

Dsu Find(Dsu a, ll key){
    Dsu &b=p[a.x][a.y][key];
    if (a.x==b.x&&a.y==b.y) return b;
    return b=Find(b,key);
}

void Union(Dsu a, Dsu b, ll key){
    a=Find(a,key); b=Find(b,key);
    if (a.x==b.x&&a.y==b.y) return;
    p[b.x][b.y][key].x=a.x;
    p[b.x][b.y][key].y=a.y;
    p[a.x][a.y][key].sz+=b.sz;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) for (int k=1;k<=n;++k) cin >> arr[i][k].b;
    for (int i=1;i<=n;++i) for (int k=1;k<=n;++k) cin >> arr[i][k].m;
    int ans=0;
    ll sect;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            p[i][k][-1]={i,k,1};
            //up
            if (arr[i][k]==arr[i-1][k]){
                // cout << "_|";
                for (auto &x:p[i-1][k]){
                    if (p[i][k].count(x.f)==0) p[i][k][x.f]={i,k,1};
                    Union(p[i][k][x.f],p[i-1][k][x.f],x.f);
                    ans=max(ans,Find(p[i][k][x.f],x.f).sz);
                }
            }
            else{
                sect=mod*arr[i][k].sect(arr[i-1][k]);
                // cout << sect << "|";
                if (sect>=0){
                    if (p[i][k].count(sect)==0) p[i][k][sect]={i,k,1};
                    if (p[i-1][k].count(sect)==0) p[i-1][k][sect]={i-1,k,1};
                    Union(p[i][k][sect],p[i-1][k][sect],sect);
                    ans=max(ans,Find(p[i][k][sect],sect).sz);
                }
            }
            //left
            if (arr[i][k]==arr[i][k-1]){
                // cout << "_ ";
                for (auto &x:p[i][k-1]){
                    if (p[i][k].count(x.f)==0) p[i][k][x.f]={i,k,1};
                    Union(p[i][k][x.f],p[i][k-1][x.f],x.f);
                    ans=max(ans,Find(p[i][k][x.f],x.f).sz);
                }
            }
            else{
                sect=mod*arr[i][k].sect(arr[i][k-1]);
                // cout << sect << " ";
                if (sect>=0){
                    if (p[i][k].count(sect)==0) p[i][k][sect]={i,k,1};
                    if (p[i][k-1].count(sect)==0) p[i][k-1][sect]={i,k-1,1};
                    Union(p[i][k][sect],p[i][k-1][sect],sect);
                    ans=max(ans,Find(p[i][k][sect],sect).sz);
                }
            }
        }
        // cout << '\n';
    }
    // for (auto x:p[2][2]){
    //    cout << "-- " << x.f << " --" << '\n';
    //     for (int i=1;i<=n;++i){
    //         for (int k=1;k<=n;++k){
    //            cout << Find(p[i][k][x.f],x.f).sz << " ";
    //         }
    //        cout << '\n';
    //     }
    // }
    
    cout << ans << '\n';

}