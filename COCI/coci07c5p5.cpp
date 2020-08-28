#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3e5+1,MAXK=1e5+1;

struct Lily{
    int x,y,f,id;
    bool operator<(const Lily &a) const {
        return x<a.x;
    }
} arr[MAXN];
vector<Lily> r[MAXK];
pii dpr[MAXK],dpc[MAXK];
int back[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1,x,y,fl;i<=n;++i){
        cin >> x >> y >> fl;
        arr[i]={x,y,fl,i};
        if (x>=arr[1].x&&y>=arr[1].y) r[y].push_back(arr[i]);
    }
    for (int i=arr[1].y;i<=arr[n].y;++i) sort(r[i].begin(),r[i].end());
    ms(dpr,-1), ms(dpc,-1), ms(ans,-1); 
    dpr[arr[1].y]=dpc[arr[1].x]={k,0};
    for (int i=arr[1].y;i<=arr[n].y;++i){
        for (Lily a:r[i]){
            if (dpr[i].f!=-1 && dpr[i].f-k+a.f>=ans[a.id]) 
                ans[a.id]=dpr[i].f-k+a.f, back[a.id]=dpr[i].s;
            if (dpc[a.x].f!=-1 && dpc[a.x].f-k+a.f>=ans[a.id])
                ans[a.id]=dpc[a.x].f-k+a.f, back[a.id]=dpc[a.x].s;
            if (ans[a.id]>=k) dpr[i]=max(dpr[i],{ans[a.id],a.id});
            if (ans[a.id]>=k) dpc[a.x]=max(dpc[a.x],{ans[a.id],a.id});
        }
    }
    cout << ans[n] << '\n';
    vector<Lily> go;
    for (int i=n;i!=0;i=back[i]) go.push_back(arr[i]);
    cout << go.size() << '\n';
    for (int i=go.size()-1;i>=0;--i){
        cout << go[i].x << " " << go[i].y << '\n';
    }
}