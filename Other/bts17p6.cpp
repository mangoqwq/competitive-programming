#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int a[MAXN], b[MAXN], bit[MAXN];
unordered_map<int,int> pos;

void Update(int idx, int val){
    for (int i=idx;i<MAXN;i+=i&-i) bit[i]+=val;
}

int Query(int idx){
    int ret=0;
    for (int i=idx;i>0;i-=i&-i) ret+=bit[i];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        pos[a[i]]=i;
    } 
    int l=1, best=0, curr=0;
    for (int i=1;i<=n;++i){
        cin >> b[i];
        if (pos[b[i]]>pos[b[i-1]]) curr++;
        else curr=1;
        if (curr>best) l=i-curr+1, best=curr;
    }
    cout << n-best << '\n';
    for (int i=l-1;i>=1;--i){
        curr=pos[b[i]]+Query(pos[b[i]]);
        cout << "F" << " " << curr << '\n';
        Update(pos[b[i]],-1);
        Update(1,1);
    }
    for (int i=best+l;i<=n;++i){
        curr=pos[b[i]]+Query(pos[b[i]]);
        cout << "B" << " " << curr << '\n';
        Update(pos[b[i]],-1);
    }
}