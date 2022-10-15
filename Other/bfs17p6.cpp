#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, MAXC=5001;

int bit[MAXC][MAXC], back[MAXN], best;
ll dp[MAXN], ans;
struct Block{ // l > w
    int l, w, h; ll p; int idx;
    bool operator<(const Block &x) const{
        if (h==x.h) return tie(l,w)<tie(x.l,x.w);
        else return h<x.h;
    }
} arr[MAXN];

void Update(int a, int b, int x){
    for (int i=a;i<MAXC;i+=i&-i){
        for (int j=b;j<MAXC;j+=j&-j){
            if (dp[x]>dp[bit[i][j]]) bit[i][j]=x;
        }
    }
}

int Query(int a, int b){
    int ret=0;
    for (int i=a;i>0;i-=i&-i){
        for (int j=b;j>0;j-=j&-j){
            if (dp[bit[i][j]]>dp[ret]) ret=bit[i][j];
        }
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b,c,d;i<=n;++i){
        cin >> a >> b >> c >> d;
        if (b>a) swap(a,b);
        arr[i]={a,b,c,d,i};
    }
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i){
        int temp=Query(arr[i].l,arr[i].w);
        dp[arr[i].idx]=dp[temp]+arr[i].p;
        back[arr[i].idx]=temp;
        Update(arr[i].l,arr[i].w,arr[i].idx);
        if (dp[arr[i].idx]>ans) ans=dp[arr[i].idx], best=arr[i].idx;
    }
    cout << ans << '\n';
    vector<int> b;
    for (int i=best;i!=0;i=back[i]) b.push_back(i);
    cout << b.size() << '\n';
    for (int x:b) cout << x << " ";
    cout << '\n';
}