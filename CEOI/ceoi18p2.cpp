#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// code is very messy, i should probably maybe fix :(

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200'001,inf=2*0x3f3f3f3f;

map<int,int> m;
int arr[MAXN],p[MAXN],sz[MAXN],bit[MAXN+5],sz2[MAXN+1],p2[MAXN+1];
vector<pii> tails;
vector<pii> t;

bool cmp(pii a, pii b){
    return a.f>b.f;
}

void insert(int idx, int val){
    for (int i=idx;i<MAXN+5;i+=i&-i){
        bit[i]=max(bit[i],val);
    }
}

int query(int idx){
    if (idx==0) return 0;
    int ans=0;
    for (int i=idx;i>=1;i-=i&-i){
        ans=max(ans,bit[i]);
    }
    return ans;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,x; cin >> n >> x;
    vector<int> b,c;
    tails.push_back({-inf,0});
    for (int i=1,a;i<=n;++i){
        cin >> a; arr[i]=a; b.push_back(a); c.push_back(a);
        if (a>tails.back().f){
            p[i]=tails.back().s;
            tails.push_back({a,i});
        }
        else{
            int idx=lower_bound(tails.begin(),tails.end(),make_pair(a,-inf))-tails.begin();
            p[i]=tails[idx-1].s;
            tails[idx]={a,i};
        }
    }
    c.push_back(333333); //space
    reverse(c.begin(),c.end());
    sort(b.begin(),b.end());
    t.push_back({inf,n+1});
    int index=1;
    for (int i=1;i<=n;++i){
        if (!m.count(b[i-1])) m[b[i-1]]=index,index++;
        sz[i]=sz[p[i]]+1;
        if (c[i]<t.back().f){
            p2[i]=t.back().s;
            t.push_back({c[i],n-i+1});
        }
        else{
            int idx=lower_bound(t.begin(),t.end(),make_pair(c[i],-inf),cmp)-t.begin();
            p2[i]=t[idx-1].s;
            t[idx]={c[i],n-i+1};
        }
        sz2[n-i+1]=sz2[p2[i]]+1;

    }
    //cout << '\n';
    m[inf]=n+1;
    int ans=0;
    for (int i=1;i<=n;++i){
        //cout << m[arr[i]] << " " << (*m.lower_bound(x+arr[i])).s << " " << query((*m.lower_bound(x+arr[i])).s) << " | ";
        ans=max(ans,sz2[i]+query((*m.lower_bound(x+arr[i])).s-1));
        insert(m[arr[i]],sz[i]);
    }
    cout << ans << '\n';
}