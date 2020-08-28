#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Sweep{double x; bool uwu;}; // 1 is in, 0 is out
vector<Sweep> arr;
int ans[MAXN];

bool cmp(Sweep a, Sweep b){
    return a.x < b.x;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    double l,r,y; cin >> l >> r >> y;
    
    double x,v,h;
    for (int i=0;i<n;++i){
        cin >> x >> v >> h;
        arr.push_back({x-((y*h)/v)+0.000001,1});
        arr.push_back({x+((y*h)/v)-0.000001,0});
    }
    sort(arr.begin(),arr.end(),cmp);
    int cnt=0; double pl=l,pr;
    for (int i=0;i<arr.size();++i){
        if (arr[i].x>r) break;
        if (arr[i].x<l){ cnt+=(arr[i].uwu*2)-1; continue;}
        pr=floor(arr[i].x);
        ans[cnt]+=pr-pl+1;
        pl=pr+1;
        cnt+=(arr[i].uwu)*2-1;
    }
    pr=r;
    ans[cnt]+=pr-pl+1;
    int tot=0;
    for (int i=0;i<=n;++i){
        tot+=ans[i];
        cout << tot << '\n';
    }

}