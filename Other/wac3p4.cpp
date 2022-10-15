#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100001;

int d[MAXN],p[MAXN],sz[MAXN],root=MAXN+1;
bool seen[MAXN];

int findp(int x){
    if (p[x]==x) return x;
    return p[x]=findp(p[x]);
}

void unions(int a,int b){
    if (sz[b]>sz[a]) swap(a,b);
    sz[findp(a)]+=sz[findp(b)];
    p[findp(b)]=findp(a);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){p[i]=i;sz[i]=1;}
    int cnt=0,odd=0;
    for (int i=0,a,b,c;i<q;++i){
        cin >> a >> b >> c;
        cnt+=!seen[a]; seen[a]=1;
        cnt+=!seen[b]; seen[b]=1;
        if (findp(a)!=findp(b)) unions(a,b);
        odd-=d[a]+d[b];
        d[a]=(d[a]+c)%2; d[b]=(d[b]+c)%2; 
        odd+=d[a]+d[b];
        //cout << cnt << " " << root << " " << sz[root] << " "<< odd << " ";
        cout << (sz[p[a]]==cnt&&(odd==0||odd==2)?"YES":"NO") << '\n';
    }
}