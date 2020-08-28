#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<ll,int> pii;
const ll mod=1e9+7,seed=131,MAXN=1e6+1;

ll power[MAXN][21];
vector<pii> arr;
map<ll,int> cnt;

ll fpow(ll p,ll k,bool domod=true){
    ll ans=1;
    for (int i=0;i<=20;++i){
        if (1&(k>>i)) { ans*=power[p][i+1]; if(domod) ans%=mod; if(!domod&&ans>=1e7) return -1;}
    }
    return ans;
}

void generate(){
    for (int i=1;i<MAXN;++i) power[i][0]=1,power[i][1]=i;
    for (int i=1;i<MAXN;++i){
        for (int k=2;k<=20;++k) power[i][k]=(power[i][k-1]*power[i][k-1])%mod;
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    generate();
    int t; cin >> t;
    while (t--){
        ll n,p; cin >> n >> p;
        cnt.clear(); arr.clear();
        for (int i=1,a;i<=n;++i){ cin >> a; cnt[a]++;}
        for (pii x:cnt){arr.push_back(x); }
        if (p==1) {cout << n%2 << '\n'; continue;}
        bool edit=true;
        int sz,sub,index;
        ll count;
        
        while (edit&&!arr.empty()){
            // for (pii x:arr) cout << x.first << " " << x.second << " | ";
            // cout << '\n';
            edit=false; sz=arr.size();
            arr.back().s%=2;
            if (arr.back().s==0){ arr.pop_back(); edit=true; }
            else{
                count=1;
                index=-1;
                for (int i=sz-2;i>=0&&count<=1e6;--i){
                    if (fpow(p,arr[i+1].f-arr[i].f,0)==-1) break;
                    count*=fpow(p,arr[i+1].f-arr[i].f,0);
                    if (arr[i].s>=count){
                        sub=count;
                        index=i;
                    }
                    else{
                        count-=arr[i].s;
                    }
                }
                if (index!=-1){
                    for (int i=sz-1;i>index;--i){
                        arr.pop_back();
                    }
                    arr.back().s-=sub;
                    edit=true;
                }
            }
        }
        vector<pii> arr1;
        for (pii x:arr){ if (x.s!=0) arr1.push_back(x); }
        if (arr1.empty()){cout << 0 << '\n'; continue;}
        
        // for (pii x:arr1) cout << x.first << " " << x.second << " | ";
        // cout << '\n';
        
        ll ans=fpow(p,arr1.back().f);
        for (int i=0;i<arr1.size()-1;++i){
            ans=(ans-((ll)arr1[i].s*fpow(p,arr1[i].f))%mod + mod)%mod;
        }
        cout << ans << '\n';
    }
}