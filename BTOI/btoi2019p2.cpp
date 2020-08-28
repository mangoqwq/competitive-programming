#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=501;

int r,c,n;
bitset<MAXN*MAXN> grid, curr, west, east; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> n; char a;
    for (int i=0;i<r;++i){
        for (int j=0;j<c;++j){
            cin >> a;
            grid[i*c+j]=a=='.';
            if (j!=c-1) west[i*c+j]=1;
            if (j!=0) east[i*c+j]=1;
        }
    }
    curr=grid;
    string op; cin >> op;
    for (char x:op){
        if (x=='N') curr=(curr>>c)&grid;
        if (x=='E') curr=((curr<<1)&east)&grid;
        if (x=='S') curr=(curr<<c)&grid;
        if (x=='W') curr=((curr>>1)&west)&grid;
        if (x=='?') curr=((curr>>c)|((curr<<1)&east)|(curr<<c)|((curr>>1)&west))&grid;
    }
    cout << curr.count() << '\n';
}