#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

struct Score{
    int a, b;
    bool operator<(const Score &x) const{
        return make_pair(x.a,x.b)>make_pair(a,b);
    }
    bool no(Score x){
        return ((x.a>a)&&(x.b<b))||((x.a<a)&&(x.b>b));
    }
    void print(){
        cout << a << "-" << b << " ";
    }
};
vector<Score> arr;
vector<vector<Score>> ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, a, b; cin >> n;
        for (int i=1;i<=n;++i){
            cin >> a >> b; b=-b;
            if (b>a) swap(a,b);
            arr.push_back({a,b});
        }
        sort(arr.begin(),arr.end());
        int p;
        for (Score x:arr){
            p=0;
            while (p<ans.size()){
                if (!x.no(ans[p].back())) break;
                p++;
            } 
            if (p==ans.size()) ans.push_back({x});
            else ans[p].push_back(x);
        }
        cout << ans.size() << '\n';
        for (auto x:ans){
            for (Score y:x) y.print();
            cout << '\n';
        }
        arr.clear();
        ans.clear();
    }
}