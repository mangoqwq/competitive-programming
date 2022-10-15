#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int t, n, q, guesses;

int qry(int a, int b, int c){
    guesses++;
    cout << a << " " << b << " " << c << '\n';
    cout.flush();
    int ret; cin >> ret;
    assert(ret!=-1);
    return ret;
}

vector<int> solve(vector<int> vec, int l, int r){
    vector<int> ret;
    if (vec.size()==0) return ret;
    if (vec.size()==1) return vec;
    if (vec.size()==2){
        if (l==-1){
            int x=qry(vec[0],vec[1],r);
            if (x==vec[0]) swap(vec[0],vec[1]);
            return vec;
        }
        else{
            int x=qry(vec[0],vec[1],l);
            if (x==vec[1]) swap(vec[0],vec[1]);
            return vec;
        }
    }
    int a=vec.back(); vec.pop_back();
    int b=vec.back(); vec.pop_back();
    if (r!=-1){
        int x=qry(a,b,r);
        if (x==a) swap(a,b);
    }
    if (l!=-1&&r==-1){
        int x=qry(a,b,l);
        if (x==b) swap(a,b);
    }
    vector<int> le, me, re;
    for (int x:vec){
        int i=qry(a,b,x);
        if (i==a) le.push_back(x);
        if (i==x) me.push_back(x);
        if (i==b) re.push_back(x);
    }
    for (int x:solve(le,l,a)) ret.push_back(x);
    ret.push_back(a);
    for (int x:solve(me,a,b)) ret.push_back(x);
    ret.push_back(b);
    for (int x:solve(re,b,r)) ret.push_back(x);
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t >> n >> q;
    while (t--){
        guesses=0;
        vector<int> arr;
        for (int i=1;i<=n;++i) arr.push_back(i);
        vector<int> ans=solve(arr,-1,-1);
        for (int i=1;i<=n;++i){
            cout << ans[i-1] << " ";
        }
        cout << '\n';
        cout.flush();
        int res; cin >> res;
        if (res==-1) break;
        q-=guesses;
    }
}