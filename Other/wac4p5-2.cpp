#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100'001;

priority_queue<ll> acorns[MAXN]; 
int p[MAXN];

int findp(int x){
    return p[x]=(p[x]==x?x:findp(p[x]));
}

void unions(int a, int b){
    a=findp(a); b=findp(b);
    if (a==b) return;
    if (acorns[a].size()<acorns[b].size()) swap(a,b);
    while (!acorns[b].empty()){
        acorns[a].push(acorns[b].top());
        acorns[b].pop();
    }
    p[b]=a;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1,a;i<=n;++i){
        p[i]=i;
        cin >> a; acorns[i].push(a);
    }
    ll l=0;
    ll op,j,a,b,c;
    for (int i=1;i<=q;++i){
        cin >> op >> j;
        j=i-1;
        if (op==1){
            cin >> a >> b;
            a^=l; b^=l;
            unions(a,b);
        }
        else if (op==2){
            cin >> a;
            a^=l;
            a=findp(a);
            l=acorns[a].top();
            acorns[a].pop(); acorns[a].push(0);
            cout << l << '\n';
        }
        else if (op==3){
            cin >> a >> c;
            a^=l; c^=l;
            a=findp(a);
            vector<ll> arr;
            while (!acorns[a].empty()){
                arr.push_back(acorns[a].top()+c);
                acorns[a].pop();
            }
            for (ll x:arr){
                acorns[a].push(x);
            }
            
        }
    }
}