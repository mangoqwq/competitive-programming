#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

vector<int> in[MAXN],out[MAXN];
int cnt[MAXN];
struct Path{
    int a,b,c;
    bool has(int x){ return a==x||b==x||c==x; }
};

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        for (int i=1;i<=n;++i) in[i].clear(),out[i].clear();
        for (int i=0,a,b;i<m;++i){
            cin >> a >> b;
            out[a].push_back(b);
            in[b].push_back(a);
        }
        vector<Path> arr,next;
        for (int i=1;i<=n;++i){
            for (int a:in[i]){
                for (int b:out[i]){
                    arr.push_back({a,i,b});
                    cnt[a]++; cnt[i]++; cnt[b]++;
                }
            }
        }
        vector<int> ans;
        int maxval, idx;
        for (int k=0;k<(4*n)/7&&!arr.empty();++k){
            maxval=0; next.clear();
            for (int i=1;i<=n;++i) if (cnt[i]>maxval) idx=i, maxval=cnt[i];
            for (Path x:arr){
                if (!x.has(idx)) next.push_back(x);
                else{
                    cnt[x.a]--, cnt[x.b]--, cnt[x.c]--;
                }
            }
            arr=next;
            ans.push_back(idx);
        }
        cout << ans.size() << '\n';
        for (int x:ans) cout << x << " ";
        cout << '\n';


    }
}