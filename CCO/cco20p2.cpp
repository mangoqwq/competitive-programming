#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int arr[MAXN],bit[MAXN];
ll ans;

void upd(int index){
    for (int i=index;i<MAXN;i+=i&-i) bit[i]++;
}

int main(){
    int n; scan(n);
    priority_queue<pii> vals; priority_queue<int> pq;    
    for (int i=1,a;i<=n;++i){ scan(a); vals.push({a,i}); }
    int pos,uwu;
    for (int i=n;i>=1;--i){
        while (!vals.empty()){
            if (vals.top().f>=i) pq.push(vals.top().s), vals.pop();
            else break;
        }
        if (pq.empty()){ cout << -1 << '\n'; return 0; }
        uwu=0;
        for (int i=pq.top();i>0;i-=i&-i) uwu+=bit[i];
        pos=pq.top()-uwu;
        for (int i=pq.top();i<MAXN;i+=i&-i) bit[i]++; 
        pq.pop();
        ans+=i-pos;
    }
    cout << ans << '\n';


}