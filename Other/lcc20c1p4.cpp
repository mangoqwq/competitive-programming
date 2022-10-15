#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=4e5+1;

int n, m;
struct Item{
    int sz, c; bool s; // bool shoe
    bool operator<(Item a){
        return make_pair(sz,s)<make_pair(a.sz,a.s);
    }
}; vector<Item> eve;

struct nd{
    int mn, set, inc;
    bool flag;
    void upd(int t, int val){
        if (t==1){
            if (flag) set+=val;
            else inc+=val;
        } else flag=1, set=val;
    }
    void push(int v,int l,int r);
} st[2*MAXN];

void nd::push(int v, int l, int r){
    if (flag){
        inc=0;
        mn=set;
        if (l!=r)
            st[v+1].flag=1, st[v+1].set=set,
            st[v+2*((l+r>>1)-l+1)].flag=1, st[v+2*((l+r>>1)-l+1)].set=set;
        flag=0;
    }
    if (inc){
        mn+=inc;
        if (l!=r){
            if (st[v+1].flag) st[v+1].set+=inc;
            else st[v+1].inc+=inc;
            if (st[v+2*((l+r>>1)-l+1)].flag) st[v+2*((l+r>>1)-l+1)].set+=inc;
            else st[v+2*((l+r>>1)-l+1)].inc+=inc;
        }
        inc=0;
    }
}

void upd(int pl, int pr, int t, int val, int v=1, int l=1, int r=2*n){ // use t=1 for increment, 2 for update
    st[v].push(v,l,r);
    if (l>pr||r<pl) return;
    if (l>=pl&&r<=pr) { st[v].upd(t,val); st[v].push(v,l,r); return; }
    int mid=l+r>>1;
    upd(pl,pr,t,val,v+1,l,mid), upd(pl,pr,t,val,v+2*(mid-l+1),mid+1,r);
    st[v].mn=min(st[v+1].mn, st[v+2*(mid-l+1)].mn);
}

int get(int pl, int pr, int v=1, int l=1, int r=2*n){
    st[v].push(v,l,r); 
    if (l>pr||r<pl) return 0x3f3f3f3f;
    if (l>=pl&&r<=pr) return st[v].mn;
    int mid=l+r>>1;
    return min(get(pl,pr,v+1,l,mid), get(pl,pr,v+2*(mid-l+1),mid+1,r));
}

map<int,vector<int>> cnt; int shoes, clowns;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i){
        int c, sz;
        cin >> c >> sz;
        eve.push_back({sz,c,1});
    }
    for (int i=1;i<=2*n;++i) upd(i,i,2,0x3f3f3f3f);
    for (int i=1;i<=n;++i){
        int c, sz;
        cin >> c >> sz;
        eve.push_back({sz,c,0});
    }
    sort(eve.begin(),eve.end()); reverse(eve.begin(),eve.end());
    int ans=0, idx=1;
    for (Item x:eve){
        if (x.s) shoes++, cnt[x.c].push_back(idx);
        else{
            clowns++;
            if (!cnt[x.c].empty()){
                // cout << cnt[x.c].back() << " " << idx << " " << get(cnt[x.c].back(),idx) << " | ";
                if (get(cnt[x.c].back(),idx)!=0){
                    upd(cnt[x.c].back(),idx,1,-1);
                    cnt[x.c].pop_back();
                    ans++;
                    clowns--;
                    shoes--;
                }
            } else upd(idx,idx,2,shoes-clowns);
        }
        if (clowns==shoes) clowns=0, shoes=0, cnt.clear();
        idx++;
    }
    cout << ans << '\n';
}