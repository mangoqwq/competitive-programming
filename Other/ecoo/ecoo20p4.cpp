#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Func{
    ll a,m;
    void s(){a+=mod;a%=mod;m%=mod;};
};
map<ll,Func> m;
int n;

void read(ll f){
    string op=""; ll x; string name; m[f].m=1;
    while (op!="END"&&n){
        cin >> op; n--;
        if (op=="ADD"){
            cin >> x;
            m[f].a+=x; m[f].s();
        }
        else if (op=="SUB"){
            cin >> x;
            m[f].a-=x; m[f].s();
        }
        else if (op=="MULT"){
            cin >> x;
            m[f].a*=x; m[f].m*=x; m[f].s();
        }
        else if (op=="FUN"){
            cin >> name;
            read(hash<string>{}(name));
        }
        else if (op=="CALL"){
            cin >> name;
            m[f].a*=m[hash<string>{}(name)].m;
            m[f].m*=m[hash<string>{}(name)].m;
            m[f].a+=m[hash<string>{}(name)].a;
            m[f].s();
        }
    }
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        m.clear();
        read(hash<string>{}("MAINFUNCTION"));
        cout << m[hash<string>{}("MAINFUNCTION")].a << '\n';
    }
}